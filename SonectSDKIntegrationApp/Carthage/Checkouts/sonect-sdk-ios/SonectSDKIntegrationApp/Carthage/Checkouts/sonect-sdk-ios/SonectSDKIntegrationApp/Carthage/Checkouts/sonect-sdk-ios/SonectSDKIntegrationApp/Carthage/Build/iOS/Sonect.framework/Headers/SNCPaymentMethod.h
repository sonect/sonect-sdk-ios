//
//  SNCPaymentMethod.h
//  Sonect
//
//  Created by Marko Hlebar on 19/12/2018.
//  Copyright © 2018 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SNCPaymentStatus) {
    SNCPaymentStatusUnknown = 0,
    SNCPaymentStatusOK,
    SNCPaymentStatusPending,
    SNCPaymentStatusCancelled,
    SNCPaymentStatusError
};

@class UIImage;
@protocol SNCTransactionMetadata;
@class SNCTransaction, SNCTransactionAmount;
typedef void(^SNCPaymentMethodHandler)(id <SNCTransactionMetadata> _Nullable transactionMetadata, NSError * _Nullable error, SNCPaymentStatus status);
typedef void(^SNCPaymentMethodAvailabilityHandler)(BOOL canPayAmount, NSError * _Nullable error);

@protocol SNCPaymentMethod <NSObject>

/**
 This method is called when the Transaction needs transaction metadata to proceed.
 A payment method should implement this method, and process the payment details to
 retrieve additional payment metadata which is processed by the SDK.

 @param amount an amount.
 @param handler a transaction metadata handler.
 */
- (void)payAmount:(SNCTransactionAmount *)amount withHandler:(SNCPaymentMethodHandler)handler;

/**
 Checks if the payment method can actually pay out the amount of money.
 Ideally, the payment method should check the amount against the users current balance.

 @param amount an amount.
 @param paymentAvailabilityHandler should return YES if payment is possible with that amount, i.e. the amount is not over balance, if not return NO and an error.
 */
- (void)canPayAmount:(SNCTransactionAmount *)amount withHandler:(SNCPaymentMethodAvailabilityHandler)paymentAvailabilityHandler;

/**
 Shorter details like last 4 digits of IBAN etc. This info is displayed in the payment tile.
 @default return detailDescription

 @return a string.
 */
@property (nullable, nonatomic, readonly) NSString *shortDescription;

/**
 Details like last 4 digits of IBAN etc. This info is displayed in the payment tile.

 @return a string.
 */
@property (nullable, nonatomic, readonly) NSString *detailDescription;

/**
 Details like type of the wallet (My wallet, Bank account) etc. This info is displayed in the payment tile.

 @return a string.
 */
@property (nullable, nonatomic, readonly) NSString *name;

/**
 An image representing the payment method. This image is displayed in the payment tile.

 @return an image.
 */
@property (nullable, nonatomic, readonly) UIImage *image;

/**
 A string that uniquely represents this payment method.
 */
@property (nonatomic, readonly) NSString *uniqueIdentifier;

@end

NS_ASSUME_NONNULL_END
