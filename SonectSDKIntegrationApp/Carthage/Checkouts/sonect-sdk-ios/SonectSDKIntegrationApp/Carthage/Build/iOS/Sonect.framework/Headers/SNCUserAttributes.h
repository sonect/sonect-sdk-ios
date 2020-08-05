//
//  SNCUserAttributes.h
//  Sonect
//
//  Created by Marko Hlebar on 09/06/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SNCUserAttributesType) {
    SNCUserAttributesTypeUndefined,
    SNCUserAttributesTypeEmployee,
    SNCUserAttributesTypeCustomer
};

@interface SNCUserAttributesTransactionLimits : NSObject
@property (nonatomic, nullable, readonly) NSDecimalNumber *dailyLimit;
@property (nonatomic, nullable, readonly) NSDecimalNumber *monthlyLimit;
@property (nonatomic, nullable, readonly) NSDecimalNumber *transactionLimit;

+ (instancetype)limits;
- (instancetype)limitsByAddingDailyLimit:(NSDecimalNumber *)dailyLimit;
- (instancetype)limitsByAddingMonthlyLimit:(NSDecimalNumber *)monthlyLimit;
- (instancetype)limitsByAddingTransactionLimit:(NSDecimalNumber *)transactionLimit;

@end

@interface SNCUserAttributes : NSObject
@property (nonatomic, readonly) SNCUserAttributesType userType;
@property (nonatomic, nullable, readonly) SNCUserAttributesTransactionLimits *transactionLimits;

+ (instancetype)attributes;
- (instancetype)attributesByAddingType:(SNCUserAttributesType)type;
- (instancetype)attributesByAddingTransactionLimits:(SNCUserAttributesTransactionLimits *)transactionLimits;

@end

NS_ASSUME_NONNULL_END
