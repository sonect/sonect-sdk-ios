//
//  ViewController.swift
//  SonectSDKIntegrationApp
//
//  Created by Marko Hlebar on 19/02/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

import UIKit
import Sonect

typealias PaymentReferenceHandler = (String, String) -> Void

protocol PaymentMethodDelegate: class {
    func paymentMethod(_ paymentMethod: PaymentMethod, wantsToPay amount:SNCTransactionAmount, handler: @escaping PaymentReferenceHandler)
}

class PaymentMethod: NSObject, SNCPaymentMethod {
    
    var title: String? = "Bank ACME"
    var shortDescription: String? = "Bank Account"
    var detailDescription: String? = "Bank account ****"
    var name: String? = "Bank ACME"
    var uniqueIdentifier: String = "BANK_IBAN"
    var image: UIImage? = UIImage(named: "Bank")!
    weak var delegate: PaymentMethodDelegate?
    
    func pay(_ amount: SNCTransactionAmount, withHandler handler: @escaping SNCPaymentMethodHandler) {
        //Process your payment and pass the payment reference & signature, this can be asynchronous
        self.delegate?.paymentMethod(self, wantsToPay: amount, handler: { (paymentReference, signature) in
            let transactionMetadata = SNCBankTransactionMetadata(amount: amount,
                                                                 paymentReference: paymentReference,
                                                                 signature: signature)
            handler(transactionMetadata, nil, .pending)
        })
    }
    
    func canPay(_ amount: SNCTransactionAmount, withHandler paymentAvailabilityHandler: @escaping SNCPaymentMethodAvailabilityHandler) {
        paymentAvailabilityHandler(true, nil);
    }
}

class ViewController: UIViewController {
    //Calculate the credentials on your server before presenting the Sonect SDK
    let sdkToken = "N2QwYmQ2ZjAtODdmNC0xMWViLTg0NTUtYmI5MmQ4YjgzNjk1OjFhOTE4OWY2NDE0NDM1YTNiZjg0Y2U5Njc3ZDc0OTQ1ZmI2OTM1ZWVhMjZkYzg2MzQwYjg1MmQzZjEzYzIxYWY="
    let userId = "User"
    let signature = "Nuj31a37m+5MIgsrZl8VwgCfcVN23gce/6onrsM19dM="

    lazy var paymentMethod: PaymentMethod = {
        let paymentMethod = PaymentMethod()
        paymentMethod.delegate = self
        return paymentMethod
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

extension ViewController: PaymentMethodDelegate {
    
    func paymentMethod(_ paymentMethod: PaymentMethod, wantsToPay amount: SNCTransactionAmount, handler: @escaping PaymentReferenceHandler) {
        let viewController = BankConfirmationViewController()
        viewController.processPayment(amount: amount, handler: handler)
        self.present(viewController, animated: true, completion: nil)
    }
}
