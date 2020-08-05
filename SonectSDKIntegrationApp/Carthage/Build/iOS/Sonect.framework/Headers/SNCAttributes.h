//
//  SNCAttributes.h
//  Sonect
//
//  Created by Marko Hlebar on 09/06/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

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
};

@interface SNCAttributes : NSObject

+ (instancetype)attributes;
- (instancetype)attributesByAddingType:(SNCAttributesType)type;
- (instancetype)attributesByAddingTransactionLimits:(SNCAttributesTransactionLimits *)transactionLimits;
- (instancetype)attributesByAddingSignatureKeys:(NSArray <NSString *>*)signatureKeys;
- (instancetype)attributesByAddingData:(NSDictionary *)data;

@end

NS_ASSUME_NONNULL_END
