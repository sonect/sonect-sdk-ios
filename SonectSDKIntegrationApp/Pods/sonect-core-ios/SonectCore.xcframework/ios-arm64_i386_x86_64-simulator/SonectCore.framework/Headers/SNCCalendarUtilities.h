//
//  SNCCalendarUtilities.h
//  SonectShop
//
//  Created by Ivan Yanakiev on 14.01.20.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNCCalendarUtilities : NSObject

+ (NSArray<NSString *> *)sncsdk_weekdayNames;

+ (NSString *)weekdayNameFromWeekdayNumber:(NSUInteger)weekdayNumber;

@end

NS_ASSUME_NONNULL_END
