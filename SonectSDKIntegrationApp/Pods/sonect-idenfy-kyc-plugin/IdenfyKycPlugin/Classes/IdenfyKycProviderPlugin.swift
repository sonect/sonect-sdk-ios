//
//  IdenfyKycProviderPlugin.swift
//  SonectShopApp
//
//  Created by Marko Hlebar on 05/03/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

import UIKit
import iDenfySDK
import SonectCore

struct ProfileIdentityVerificationStatus {
    let authenticationStatus: iDenfySDK.AuthenticationResultResponse?
    let errorStatus: iDenfySDK.IdenfyErrorResponse?
    let userExit: Bool?
}

class IdenfyKycResult: NSObject, SNCKycCheckResult {
    var data: Any? = nil
    var error: Error? = nil
    var status: SNCKycVerificationStatus = .unkown
    
    init(verificationStatus: ProfileIdentityVerificationStatus) {
        data = verificationStatus
        
        if let _ = verificationStatus.userExit {
            status = .userCancelled
        }
        else if let errorStatus = verificationStatus.errorStatus {
            status = .failure
            error = NSError(domain: "ch.sonect.idenfyKycPlugin",
                            code: 1000,
                            userInfo: [NSLocalizedDescriptionKey: errorStatus.message])
        }
        else if let idenfyStatus = verificationStatus.authenticationStatus?.idenfyIdentificationStatus {
            switch idenfyStatus {
            case .APPROVED: fallthrough
            case .REVIEWING:
                status = .pending
            case .DENIED: fallthrough
            case .UNKNOWN: fallthrough
            case .SUSPECTED:
                status = .failure
                error = NSError(domain: "ch.sonect.idenfyKycPlugin",
                                code: 1001,
                                userInfo: [NSLocalizedDescriptionKey: verificationStatus.authenticationStatus?.errorMessage?.en ?? "Unknown Kyc Error"])
            @unknown default:
                break
            }
        }
    }
}

public class IdenfyKycProviderPlugin: NSObject, SNCKycProviderPlugin {
        
    var flamingoColor = UIColor.systemPink
    var whiteColor = UIColor.white
    var blackColor = UIColor.black
    
    public var platform: String = "idenfy"
    
    private var idenfyController: IdenfyController?
    private var idenfyViewController: UIViewController?
    
    public func startKycCheck(_ presentingViewController: UIViewController, configuration: [AnyHashable : Any], handler: @escaping SNCKycCheckResultHandler) {
        guard let token = configuration["token"] as? String else {
            fatalError("Missing tokrn in configuration parameters.")
        }
        
        let idenfyUISettings = IdenfyUIBuilderV2()
            .withInstructions(true)
            .build()
                 
        let idenfySettings = IdenfyBuilderV2()
            .withUISettingsV2(idenfyUISettings)
            .withDocumentIssuingCountrySkipped()
            .withAuthToken(token)
            .build()
        
        let idenfyController = IdenfyController.shared
        idenfyController.initializeIdenfySDKV2WithManual(idenfySettingsV2: idenfySettings)
        let idenfyViewController = idenfyController.instantiateNavigationController()
        
        idenfyController.handleIDenfyCallbacks(
            onSuccess: {[weak self] (response) in
                let status = ProfileIdentityVerificationStatus(
                    authenticationStatus: response,
                    errorStatus: nil,
                    userExit: nil)
                self?.dismiss(status: status, handler: handler)
            },
            onError: {[weak self] (response) in
                let status = ProfileIdentityVerificationStatus(
                    authenticationStatus: nil,
                    errorStatus: response,
                    userExit: nil)
                self?.dismiss(status: status, handler: handler)
            },
            onUserExit: { [weak self] in
                //User exited the SDK without completing identification process.
                let status = ProfileIdentityVerificationStatus(
                    authenticationStatus: nil,
                    errorStatus: nil,
                    userExit: true)
                self?.dismiss(status: status, handler: handler)
        })
        
        presentingViewController.present(idenfyViewController, animated: true, completion: nil)
        
        self.idenfyController = idenfyController
        self.idenfyViewController = idenfyViewController
    }
    
    private func dismiss(status: ProfileIdentityVerificationStatus, handler: @escaping SNCKycCheckResultHandler) {
        guard let idenfyViewController = idenfyViewController else {
            return
        }
        
        let result = IdenfyKycResult(verificationStatus: status)
        handler(result)
        
        idenfyViewController.dismiss(animated: true, completion: { [weak self] in
            self?.idenfyController = nil
            self?.idenfyViewController = nil
        })
    }
}
