//
//  SNCTransactionMetadata.h
//  Sonect
//
//  Created by Marko Hlebar on 07/03/2019.
//  Copyright © 2019 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString *const SNCTransactionMetadataKey NS_STRING_ENUM;

FOUNDATION_EXPORT SNCTransactionMetadataKey SNCTransactionMetadataKeyAmount;
FOUNDATION_EXPORT SNCTransactionMetadataKey SNCTransactionMetadataKeyCurrency;
FOUNDATION_EXPORT SNCTransactionMetadataKey SNCTransactionMetadataKeyOpen;
FOUNDATION_EXPORT SNCTransactionMetadataKey SNCTransactionMetadataKeyPaymentId;
FOUNDATION_EXPORT SNCTransactionMetadataKey SNCTransactionMetadataKeyPaymentMethodId;
FOUNDATION_EXPORT SNCTransactionMetadataKey SNCTransactionMetadataKeyPaymentMethod;
FOUNDATION_EXPORT SNCTransactionMetadataKey SNCTransactionMetadataKeySignature;
FOUNDATION_EXPORT SNCTransactionMetadataKey SNCTransactionMetadataKeyTo;
FOUNDATION_EXPORT SNCTransactionMetadataKey SNCTransactionMetadataKeyType;
FOUNDATION_EXPORT SNCTransactionMetadataKey SNCTransactionMetadataKeyTrxType;

@protocol SNCTransactionMetadata <NSObject>

/**
 Implement me in a subclass.
 */
@property (nonnull, readonly) NSDictionary <SNCTransactionMetadataKey, NSString *> *serialized;
@end

@class SNCTransactionAmount;
@interface SNCBankTransactionMetadata : NSObject <SNCTransactionMetadata>

/**
 Creates a transaction metadata object for closed bank API-s,
 where payment reference is obtained from the Bank implementing the
 payment resolution.

 @param amount an amount.
 @param paymentReference a unique payment reference, obtained from the bank.
 @param signature a signature, calculated by the bank.
 @return transaction metadata.
 */
+ (instancetype)transactionMetadataWithAmount:(SNCTransactionAmount *)amount
                             paymentReference:(NSString *)paymentReference
                                    signature:(NSString *)signature;

@end

NS_ASSUME_NONNULL_END
