//
//  BankConfirmationViewController.swift
//  SonectSDKIntegrationApp
//
//  Created by Marko Hlebar on 02/03/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

import UIKit
import Sonect

class BankConfirmationViewController: UIViewController {

    var paymentReferenceHandler: PaymentReferenceHandler?
    @IBOutlet var amountLabel: UILabel!
    
    func processPayment(amount: SNCTransactionAmount, handler: @escaping PaymentReferenceHandler) {
        self.paymentReferenceHandler = handler;
        
        amountLabel.text = "\(amount.value.stringValue) \(amount.currency)"
    }
    
    @IBAction func confirm(_ sender: Any) {
        guard let handler = self.paymentReferenceHandler else {
            return
        }
        
        handler("_YOUR_PAYMENT_REFERENCE_", "_YOUR_SIGNATURE_")
        
        self.dismiss(animated: true, completion: nil)
    }    
}
