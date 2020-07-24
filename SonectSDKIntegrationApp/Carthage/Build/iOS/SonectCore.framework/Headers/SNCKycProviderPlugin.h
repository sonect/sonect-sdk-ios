//
//  SNCKycProviderPlugin.h
//  SonectShop
//
//  Created by Marko Hlebar on 02/03/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SNCKycVerificationStatus) {
    SNCKycVerificationStatusUnkown = 0,
    SNCKycVerificationStatusUserCancelled,
    SNCKycVerificationStatusSuccess,
    SNCKycVerificationStatusPending,
    
    //Failure status should be supplemented with an error.
    SNCKycVerificationStatusFailure
};

@protocol SNCKycCheckResult <NSObject>
@property (nullable, readonly) id data;
@property (nullable, readonly) NSError *error;
@property (readonly) SNCKycVerificationStatus status;
@end

typedef void(^SNCKycCheckResultHandler)(id <SNCKycCheckResult> result);
@protocol SNCKycProviderPlugin <NSObject>

@property (nonnull, readonly) NSString *platform;

- (void)startKycCheck:(UIViewController *)presentingViewController
        configuration:(NSDictionary *)configuration
              handler:(SNCKycCheckResultHandler)handler;
@end

NS_ASSUME_NONNULL_END
