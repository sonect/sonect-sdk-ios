//
//  SNCSonectPaymentDataSource.h
//  Sonect
//
//  Created by Marko Hlebar on 22/03/2019.
//  Copyright © 2019 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SNCPaymentContext.h"

NS_ASSUME_NONNULL_BEGIN

@protocol SNCPaymentMethod;
typedef void(^SNCPaymentMethodsHandler)(NSArray <id <SNCPaymentMethod>> * _Nullable, NSError * _Nullable);

@class SNCSonect;
@protocol SNCSonectPaymentDataSource <NSObject>

/**
 Asks the data source to load available payment methods

 @param sonect a sonect instance.
 @param context a payment context to load payment methods for.
 @param handler a payment methods handler.
 */
- (void)sonect:(SNCSonect *)sonect loadAvailablePaymentMethodsForContext:(SNCPaymentContext)context handler:(SNCPaymentMethodsHandler)handler;

@end

NS_ASSUME_NONNULL_END
