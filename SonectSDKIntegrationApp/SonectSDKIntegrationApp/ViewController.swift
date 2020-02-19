//
//  ViewController.swift
//  SonectSDKIntegrationApp
//
//  Created by Marko Hlebar on 19/02/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

import UIKit
import Sonect

class PaymentMethod: NSObject, SNCPaymentMethod {
    
    var shortDescription: String? = "Bank Account"
    var detailDescription: String? = "Bank account ****"
    var name: String? = "Bank ACME"
    var uniqueIdentifier: String = "BANK_IBAN"
    var image: UIImage? = UIImage(named: "Bank")!
    
    func pay(_ amount: SNCTransactionAmount, withHandler handler: @escaping SNCPaymentMethodHandler) {
        //Process your payment and pass the payment reference & signature, this can be asynchronous
        DispatchQueue.main.asyncAfter(deadline: .now() + 1.0) {
            let transactionMetadata = SNCBankTransactionMetadata(amount: amount,
                                                                 paymentReference: "_YOUR_PAYMENT_REFERENCE_",
                                                                 signature: "_YOUR_SIGNATURE_")
            handler(transactionMetadata, nil, .pending)
        }
    }
    
    func canPay(_ amount: SNCTransactionAmount, withHandler paymentAvailabilityHandler: @escaping SNCPaymentMethodAvailabilityHandler) {
        paymentAvailabilityHandler(true, nil);
    }
}

class ViewController: UIViewController {
    //Calculate the credentials on your server before presenting the Sonect SDK
    let sdkToken = "_YOUR_TOKEN_"
    let userId = "_YOUR_USER_ID_"
    let signature = "_YOUR_SIGNATURE_"

    let paymentMethod = PaymentMethod()
    
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
