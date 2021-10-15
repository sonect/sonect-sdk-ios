//
//  ViewController.swift
//  SonectSDKIntegrationApp
//
//  Created by Marko Hlebar on 19/02/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

import UIKit
import Sonect

class ViewController: UIViewController {
    //Calculate the credentials on your server before presenting the Sonect SDK
    let sdkToken = "NTkxMTI4YjAtN2Q5NC0xMWVhLTgyMjAtOTVmNmUxZWI3MTBiOjc5YWM3NjZjMzg2NzhlYWYzN2Y2YzYyODUyNWEwMmVjNGNlZTMwZTE3MjJiZjc2MjMwMDgxN2EwMzIwYzZiOTQ="
    let userId = "UserSonect"
    let signature = "YRelUSO+ZU497b/roRW6BBv1kypcfKylV5ccnd7en1c="
    let hmacKey = "fa4cde2db0b8132b41f9a64d06f410eaf308c96dae41aad045aab851ca16afae"
    let clientId = "591128b0-7d94-11ea-8220-95f6e1eb710b"

    lazy var paymentMethod: PaymentMethod = {
        return PaymentMethod(clientId: clientId,
                             userId: userId,
                             bundleId: Bundle.main.bundleIdentifier!,
                             hmacKey: hmacKey)
    }()
    
    @IBAction func presentSdk(_ sender: Any) {
        let credentials = SNCCredentials(sdkToken: sdkToken,
                                         userId: userId,
                                         signature: signature)
        SNCSonect.present(with: credentials,
                          configuration: SNCConfiguration.default(),
                          presenting: self)
        SNCSonect.paymentDataSource = self
    }
}

extension ViewController: SNCSonectPaymentDataSource {
   
    func sonect(_ sonect: SNCSonect, loadAvailablePaymentMethodsFor context: SNCPaymentContext, handler: @escaping SNCPaymentMethodsHandler) {
        //Create your payment method, this can be asynchronous
        handler([paymentMethod], nil)
    }
}
