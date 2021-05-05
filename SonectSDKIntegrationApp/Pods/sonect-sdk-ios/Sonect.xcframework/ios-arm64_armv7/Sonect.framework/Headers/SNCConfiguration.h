//
//  SNCConfiguration.h
//  SonectSDK
//
//  Created by Bruno Sousa on 21/12/2018.
//  Copyright © 2018 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SonectCore/SonectDefines.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    SNCCodeTypeBarcode = 0,
    SNCCodeTypeQR = 1,
} SNCCodeType SNC_SWIFT_NAME(CodeType);

@class SNCAttributes;

typedef NSString * SNCSonectTransactionStatus NS_TYPED_ENUM;

FOUNDATION_EXPORT SNCSonectTransactionStatus const SNCSonectTransactionStatusExpired;
FOUNDATION_EXPORT SNCSonectTransactionStatus const SNCSonectTransactionStatusCancelled;
FOUNDATION_EXPORT SNCSonectTransactionStatus const SNCSonectTransactionStatusRejected;
FOUNDATION_EXPORT SNCSonectTransactionStatus const SNCSonectTransactionStatusConfirmed;

SNC_SWIFT_NAME(Configuration)
@interface SNCConfiguration : NSObject

/**
 A 2 digit ISO country code i.e. "CH" for Switzerland
 */
@property (nonatomic, copy, readonly) NSString* alpha2CountryCode;

/**
 Set allowed country codes.
 Example: would be US and Switzerland
 @[@1, @41]
 */
@property (nonatomic, copy, readonly) NSArray <NSNumber *> *allowedCountryCodes;

/**
 The user's preferred currency i.e. "CHF" for Swiss Francs
 */
@property (nonatomic, nullable, copy, readonly) NSString* currency;

/**
 The welcome name used on dashboard screen.
 */
@property (nonatomic, nullable, copy, readonly) NSString* dashboardWelcomeName;

/**
 A default withdraw amount index in the Withdraw View Controller amount picker control.
 This control also remembers the user's last picked value.
 */
@property (nonatomic, readonly) NSUInteger defaultWithdrawAmountIndex;

/**
 This value determines if upon opening the SDK, the user should be presented with an
 active transaction.
 @default NO
 */
@property (nonatomic, readonly) BOOL shouldPresentTransactionIfAvailable;

/**
This value determines which code type should be preselected when viewing transaction.
@default SNCCodeTypeBarcode
*/
@property (nonatomic, readonly) SNCCodeType preferredWithdrawCodeType;

/**
 Additional attributes that could be of variable nature.
*/
@property (nonatomic, strong, nullable) SNCAttributes *attributes;
/**
 Dictionary which defines visibility of payment reference section of transaction receipt.
 Should be placed at "SonectTransactionStatusToPaymentReferenceVisibility" SonectConfiguration.plist's raw key
 Valid status keys are represented via SNCSonectTransactionStatus with variable suffix part as raw key, i.e. SNCSonectTransactionStatusConfirmed -> "confirmed"
*/
@property (nonatomic, strong, readonly) NSDictionary < SNCSonectTransactionStatus, NSNumber *> *transactionStatusToPaymentReferenceVisibility;
/**
 Initializes the configuration with a designated configuration plist file.

 @param filePath a file path.
 @return a configuration.
 */
- (instancetype)initWithContentsOfFile:(NSString *)filePath;

/**
 Initializes the configuration by loading the SonectConfiguration.plist

 @return a configuration.
 */
+ (instancetype)defaultConfiguration;

+ (instancetype) new  NS_UNAVAILABLE;
- (instancetype) init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
