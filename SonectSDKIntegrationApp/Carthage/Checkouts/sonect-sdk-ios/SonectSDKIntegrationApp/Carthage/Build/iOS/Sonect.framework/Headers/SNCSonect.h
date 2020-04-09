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

@class SNCConfiguration, SNCCredentials, SNCUI, UIViewController;
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
 The Sonect UI overrides .
 The SDK client can override the default UI by providing the UI settings upfront,
 
 @discussion you can only set the ui once, if you try to set it when SDK is already presented, or override
 already set ui, an exception will be raised.
 */
@property (class, nullable) SNCUI *ui;

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

/**
 Dismiss the Sonect View Controller programatically.
 @discussion The SDK navigation dismisses naturally itself by user interaction.
 You shouldn't call this method unless absolutely necessary for scenarios like Logout etc.
 */
+ (void)dismiss;

@end

NS_ASSUME_NONNULL_END
