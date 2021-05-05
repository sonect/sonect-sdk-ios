//
//  SNCCountries.h
//  SonectCore
//
//  Created by Marko Hlebar on 23/02/2021.
//  Copyright © 2021 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// Returns an alphabetically ordered array of supported country codes.
extern NSArray <NSString *>* SNCSupportedCountryCodesInCountry(NSString *countryCode);

NS_ASSUME_NONNULL_END
