//
//  SNCAnalitycsEvents.h
//  SonectSDK
//
//  Created by Oleksandr Bedzyk on 20.05.2020.
//  Copyright © 2020 Sonect. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <SonectCore/SonectDefines.h>

typedef NSString *const SNCAnalyticsEvent NS_STRING_ENUM SNC_SWIFT_NAME(AnalyticsEvent);
typedef NSString *const SNCAnalyticsParameter NS_STRING_ENUM SNC_SWIFT_NAME(AnalyticsParameter);

#pragma mark - Events
FOUNDATION_EXPORT SNCAnalyticsEvent SNCAnalyticsEventTermsAndConditionSigned;
FOUNDATION_EXPORT SNCAnalyticsEvent SNCAnalyticsEventShopOnboardingCompleted;
