//
//  SNCSonect.h
//  Sonect
//
//  Created by Marko Hlebar on 07/12/2018.
//  Copyright © 2018 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SNCSonectPaymentDataSource.h"

NS_ASSUME_NONNULL_BEGIN

@class SNCConfiguration, SNCCredentials, UIViewController;
@interface SNCSonect : NSObject

/**
 The current configuration that is passed through the presentWithCredentials: method.
 */
@property (class, nullable, readonly) SNCConfiguration *currentConfiguration;

/**
 The current credentials that are passed through the presentWithCredentials: method.
 */
@property (class, nullable, readonly) SNCCredentials *currentCredentials;

/**
 The payment data source.
 The SDK client can override the default payment data source to their implementation,
 in order to provide custom payment methods.
 */
@property (class) id <SNCSonectPaymentDataSource> paymentDataSource;

/**
 Presents the Sonect View Controller on the presenting view controller, with credentials and
 configuration provided by the client.
 The presented view controller is wrapped in a navigation controller.

 @param credentials the credentials.
 @param configuration the configuration.
 @param presentingViewController a presenting view controller.
 */
+ (void)presentWithCredentials:(SNCCredentials *)credentials
                 configuration:(SNCConfiguration *)configuration
      presentingViewController:(UIViewController *)presentingViewController;

@end

NS_ASSUME_NONNULL_END
