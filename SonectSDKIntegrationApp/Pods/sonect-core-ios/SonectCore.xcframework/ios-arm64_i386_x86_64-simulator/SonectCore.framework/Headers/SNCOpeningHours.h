//
//  SNCOpeningHours.h
//  SonectShop
//
//  Created by Ivan Yanakiev on 13.01.20.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, SNCDay) {
    SNCDayMonday = 1,
    SNCDayTuesday = 2,
    SNCDayWednesday = 3,
    SNCDayThursday = 4,
    SNCDayFriday = 5,
    SNCDaySaturday = 6,
    SNCDaySunday = 0,
};

@interface SNCDayTime: NSObject <NSSecureCoding, NSCopying>
@property (nonatomic, readonly) SNCDay day;
@property (nonatomic, copy, readonly) NSString *time;

/// Initialize a daytime with a day and time
/// @param day day.
/// @param time a time in format "HHmm".
- (instancetype)initWithDay:(SNCDay)day andTime:(NSString *)time;

@end

@interface SNCPeriod: NSObject <NSSecureCoding>

@property (nonatomic, strong, readonly) SNCDayTime *open;
@property (nonatomic, strong, readonly) SNCDayTime *close;
@property (nonatomic, getter=isClosed, readonly) BOOL closed;

/// Initialize a period with opening and closing time.
/// @param openingTime opening time.
/// @param closingTime closing time.
- (instancetype)initWithOpeningTime:(SNCDayTime *)openingTime andClosingTime:(SNCDayTime *)closingTime;

@end

@interface SNCOpeningHours: NSObject <NSSecureCoding>

+ (instancetype)openAllDayOpeningHours;

@property (nonatomic, readonly) BOOL openNow;
@property (nonatomic, copy, readonly) NSArray<NSString*> *weekdayText;

/// Periods of working time. IMPORTANT: we support max 2 periods per SNCDay, i.e. property stores up to 14 distinct periods. The periods that won't fit the day will be skipped.
@property (nonatomic, copy, readonly) NSArray<SNCPeriod*> *periods;

/// Initialize opening hours with a set of periods.
/// @param periods the periods.
- (instancetype)initWithPeriods:(NSArray<SNCPeriod*> *)periods;
@end

NS_ASSUME_NONNULL_END
