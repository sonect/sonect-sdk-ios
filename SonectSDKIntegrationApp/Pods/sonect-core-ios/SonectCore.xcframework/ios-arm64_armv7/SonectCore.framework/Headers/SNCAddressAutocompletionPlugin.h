//
//  SNCAddressAutocompletionPlugin.h
//  SonectShop
//
//  Created by Ivan Yanakiev on 7.04.20.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SonectDefines.h"

NS_ASSUME_NONNULL_BEGIN

@class SNCOpeningHours;

SNC_SWIFT_NAME(AddressDetails)
@protocol SNCAddressDetails <NSObject>
@property (nullable, copy, readonly) NSString *country;
@property (nullable, copy, readonly) NSString *countryCode;
@property (nullable, copy, readonly) NSString *streetName;
@property (nullable, copy, readonly) NSString *streetNumber;
@property (nullable, copy, readonly) NSString *city;
@property (nullable, copy, readonly) NSString *zip;
@property (nullable, copy, readonly) NSString *state;
@property (readonly) CGFloat latitude;
@property (readonly) CGFloat longitude;
@end

SNC_SWIFT_NAME(AddressPrediction)
@protocol SNCAddressPrediction <NSObject>
@property (copy, readonly) NSString *addressId;
@property (copy, readonly) NSString *mainText;
@property (copy, readonly) NSString *secondaryText;
@end

SNC_SWIFT_NAME(ShopDetails)
@protocol SNCShopDetails <NSObject>
@property (copy, readonly) NSString *name;
@property (copy, readonly) id <SNCAddressDetails> address;
@property (copy, readonly) SNCOpeningHours *openingHours;
@property (copy, readonly) NSArray <NSString*> *types;
@property (copy, nullable, readonly) UIImage *shopImage;
@end

SNC_SWIFT_NAME(ShopCandidate)
@protocol SNCShopCandidate <NSObject>
@property (copy, readonly) NSString *shopId;
@property (copy, readonly) NSString *name;
@property (copy, readonly) NSString *address;
@property (copy, readonly) NSArray <NSString*> *types;
@end

SNC_SWIFT_NAME(ShopSearch)
@protocol SNCShopSearch <NSObject>
@property (readonly) NSArray <id<SNCShopCandidate>> *candidates;
@end

SNC_SWIFT_NAME(AddressAutocompletion)
@protocol SNCAddressAutocompletion <NSObject>
@property (readonly) NSArray <id<SNCAddressPrediction>> *predictions;
@end

typedef void(^SNCAddressDetailsResultHandler)(id<SNCAddressDetails> _Nullable addressDetails, NSError * _Nullable error) SNC_SWIFT_NAME(AddressDetailsResultHandler);
typedef void(^SNCAddressAutocompletionResultHandler)(id<SNCAddressAutocompletion> _Nullable autocompleteAddress, NSError * _Nullable error) SNC_SWIFT_NAME(AddressAutocompletionResultHandler);
typedef void(^SNCShopSearchResultHandler)(id<SNCShopSearch> _Nullable shopSearch, NSError * _Nullable error) SNC_SWIFT_NAME(ShopSearchResultHandler);
typedef void(^SNCShopDetailsResultHandler)(id<SNCShopDetails> _Nullable shopDetails, NSError * _Nullable error) SNC_SWIFT_NAME(ShopDetailsResultHandler);

SNC_SWIFT_NAME(AddressDetails)
@protocol SNCAddressAutocompletionPlugin <NSObject>

- (void)addressAutocompletionForSearchTerm:(NSString *)searchTerm
                               countryCode:(NSString *)countryCode
                         completionHandler:(SNCAddressAutocompletionResultHandler)compleionHandler;
 
- (void)adressDetailsForAddressId:(NSString *)addressId
                completionHandler:(SNCAddressDetailsResultHandler)compleionHandler;

- (void)shopsForSearchTerm:(NSString *)searchTerm
               countryCode:(NSString *)countryCode
         completionHandler:(SNCShopSearchResultHandler)compleionHandler;

- (void)shopDetailsForShopId:(NSString *)shopId
           completionHandler:(SNCShopDetailsResultHandler)compleionHandler;

@end

NS_ASSUME_NONNULL_END
