//
//  SNCTransactionAmount.h
//  Sonect
//
//  Created by Marko Hlebar on 19/03/2019.
//  Copyright © 2019 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNCTransactionAmount : NSObject <NSCopying>

/**
 Amount of money to do transaction with.
 */
@property (nonatomic, copy, readonly) NSDecimalNumber *value;

/**
 Amount of money for fees, default = 0.
 */
@property (nonatomic, copy, readonly) NSDecimalNumber *feeValue;

/**
 Currency code. i.e. CHF
 */
@property (nonatomic, copy, readonly) NSString *currency;

/**
 Creates a transaction amount object.

 @param value a value, amount of money to do transaction with.
 @param currency a currency code. i.e. CHF
 @return a transaction amount object.
 */
+ (instancetype)transactionAmountWithValue:(NSDecimalNumber *)value
                                  currency:(NSString *)currency;

/**
 Creates a transaction amount object.

 @param value a value, amount of money to do transaction with.
 @param feeValue a value, amount of money for fees.
 @param currency a currency code. i.e. CHF
 @return a transaction amount object.
 */
+ (instancetype)transactionAmountWithValue:(NSDecimalNumber *)value
                                  feeValue:(NSDecimalNumber *)feeValue
                                  currency:(NSString *)currency;

/**
 Returns a 0 amount in a currency.

 @param currency a currency.
 @return an amount.
 */
+ (instancetype)zeroAmountWithCurrency:(NSString *)currency;

/**
 Compares two transaction amounts, including fees, returns NSNotFound and throws an error if the other amount is not in the same currency.
 @discussion a transaction amount with value = 10, feeValue = 1 will compare equal to amount with value = 1, feeValue = 10, but will fail isEqual: test.

 @param otherAmount an amount.
 @param error an error if any.
 @return a comparison result. Will return NSNotFound if there was and error.
 */
- (NSComparisonResult)compare:(SNCTransactionAmount *)otherAmount error:(NSError *_Nullable *_Nullable)error;

/**
 Compares two transaction amounts, including fees, returns NSNotFound if the other amount is not in the same currency.
 @discussion a transaction amount with value = 10, feeValue = 1 will compare equal to amount with value = 1, feeValue = 10, but will fail isEqual: test.

 @param otherAmount an amount.
 @return a comparison result. Will return NSNotFound if there was and error.
 */
- (NSComparisonResult)compare:(SNCTransactionAmount *)otherAmount;

/**
Returns string which contains 'value' with 2 decimal digits and 'currency' in locale-dependent form."
@discussion a transaction amount with value = 10 and currency = CHF might return "10.00 CHF".
*/
- (NSString *)toString;

@end

@interface SNCTransactionAmount (Formatting)

/**
Returns a formatted currency, i.e. USD, will be represented as $
*/
@property (nonatomic, readonly) NSString *formattedCurrency;

@end

NS_ASSUME_NONNULL_END
