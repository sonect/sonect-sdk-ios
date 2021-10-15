//
//  ClosedBankPaymentMethod.swift
//  OpenBankIntegrationApp
//
//  Created by Marko Hlebar on 25/03/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

import UIKit
import Sonect

class PaymentMethod: NSObject, SNCPaymentMethod {
    
    let clientId: String
    let userId: String
    let bundleId: String
    let hmacKey: String
    
    init(clientId: String, userId: String, bundleId: String, hmacKey: String) {
        self.clientId = clientId
        self.userId = userId
        self.hmacKey = hmacKey;
        self.bundleId = bundleId
    }

    func pay(_ amount: SNCTransactionAmount, withHandler handler: @escaping SNCPaymentMethodHandler) {
        let date = "CAPTURED"
        let paymentReference = self.paymentReference
        
        //Calculate the signature on your backend.
        let signature = self.signature(for: self.clientId,
                                  bundleId: self.bundleId,
                                  userId: self.userId,
                                  paymentReference: paymentReference,
                                  value: amount.value.stringValue,
                                  currency: amount.currency,
                                  date: date,
                                  hmacKey: self.hmacKey)
        
        let transactionMetadata = SNCBankTransactionMetadata(amount: amount,
                                                             paymentReference: paymentReference,
                                                             signature: signature)
        transactionMetadata.date = date
        handler(transactionMetadata, nil, .pending)
    }

    func canPay(_ amount: SNCTransactionAmount, withHandler paymentAvailabilityHandler: @escaping SNCPaymentMethodAvailabilityHandler) {
        let balanceAmount = SNCTransactionAmount(value: 100, currency: amount.currency)
        let canPay = balanceAmount.compare(amount) == .orderedDescending
        let error: NSError? = canPay ? nil : NSError(domain: Bundle.main.bundleIdentifier! + ".error", code: 1, userInfo: [
            NSLocalizedDescriptionKey: "Not enough balance max (\(balanceAmount.value.stringValue))",
            "SNCLocalizedColorCodeKey": UIColor.yellow,
        ])
        
        //Fake server response time
        DispatchQueue.main.asyncAfter(deadline: .now() + 1.0) {
            paymentAvailabilityHandler(canPay, error);
        }
    }

    var attributedTitle: NSAttributedString? {
        return NSAttributedString(string: self.title!)
    }

    var shortDescription: String? {
        return "Bank account"
    }

    var detailDescription: String? {
        return "Bank account ****"
    }

    var title: String? {
        return "Closed API Bank"
    }

    var image: UIImage? {
        return UIImage(named: "Bank")!
    }

    var uniqueIdentifier: String {
        return "BANK_IBAN_3"
    }
    
    lazy var paymentReference: String = {
        return UUID().uuidString
    }()

    func signature(for clientId: String, bundleId: String, userId: String, paymentReference: String, value: String, currency: String, date: String, hmacKey:String) -> String {
        return SNCHmacCalculator.signature(withParameters: [clientId, bundleId, userId, paymentReference, value, currency, date],
                                           key: hmacKey,
                                           encodeKey: false)
    }
}
