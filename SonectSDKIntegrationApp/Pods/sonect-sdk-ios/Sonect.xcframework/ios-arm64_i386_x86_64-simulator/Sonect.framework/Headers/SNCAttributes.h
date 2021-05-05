//
//  SNCAttributes.h
//  Sonect
//
//  Created by Marko Hlebar on 09/06/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SonectCore/SonectDefines.h>

NS_ASSUME_NONNULL_BEGIN

SNC_SWIFT_NAME(AttributesTransactionLimits)
@interface SNCAttributesTransactionLimits : NSObject

+ (instancetype)limits;
- (instancetype)limitsByAddingDailyLimit:(NSDecimalNumber *)dailyLimit;
- (instancetype)limitsByAddingWeeklyLimit:(NSDecimalNumber *)weeklyLimit;
- (instancetype)limitsByAddingMonthlyLimit:(NSDecimalNumber *)monthlyLimit;
- (instancetype)limitsByAddingYearlyLimit:(NSDecimalNumber *)yearlyLimit;

@end

typedef NS_ENUM(NSUInteger, SNCAttributesType) {
    SNCAttributesTypeUndefined,
    SNCAttributesTypeEmployee,
    SNCAttributesTypeCustomer
} SNC_SWIFT_NAME(AttributesType);

SNC_SWIFT_NAME(Attributes)
@interface SNCAttributes : NSObject

+ (instancetype)attributes;
- (instancetype)attributesByAddingType:(SNCAttributesType)type;
- (instancetype)attributesByAddingFreeTrial:(BOOL)freeTrial;
- (instancetype)attributesByAddingResidualTransactionLimits:(SNCAttributesTransactionLimits *)residualTransactionLimits;
- (instancetype)attributesByAddingMaxTransactionLimits:(SNCAttributesTransactionLimits *)maxTransactionLimits;
- (instancetype)attributesByAddingSignatureKeys:(NSArray <NSString *>*)signatureKeys;
- (instancetype)attributesByAddingData:(NSDictionary *)data;

// MARK: Deprecated
- (instancetype)attributesByAddingTransactionLimits:(SNCAttributesTransactionLimits *)transactionLimits __deprecated_msg("Use attributesByAddingResidualTransactionLimits or attributesByAddingMaxTransactionLimits instead. Implementation calls attributesByAddingResidualTransactionLimits.");
@end

NS_ASSUME_NONNULL_END
