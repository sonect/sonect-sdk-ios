//
//  SNCOpeningHours.h
//  SonectShop
//
//  Created by Ivan Yanakiev on 13.01.20.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNCDayTime: NSObject <NSSecureCoding>

@property (nonatomic, readonly) NSUInteger day;
@property (nonatomic, copy, readonly) NSString *time;

- (instancetype)initWithDay:(NSUInteger)day andTime:(NSString *)time;

@end

@interface SNCPeriod: NSObject <NSSecureCoding>

@property (nonatomic, copy, readonly) SNCDayTime *open;
@property (nonatomic, copy, readonly) SNCDayTime *close;
@property (nonatomic, readonly) BOOL isClosed;

- (instancetype)initWithOpeningTime:(SNCDayTime *)openingTime andClosingTime:(SNCDayTime *)closingTime;

@end

@interface SNCOpeningHours: NSObject <NSSecureCoding>

@property (nonatomic, readonly) BOOL openNow;
@property (nonatomic, copy, readonly) NSArray<NSString*> *weekdayText;

/// Periods of open time. IMPORTANT: periods day should be in range 0 - 6!
@property (nonatomic, copy, readonly) NSArray<SNCPeriod*> *periods;

- (instancetype)initWithPeriods:(NSArray<SNCPeriod*> *)periods;

@end

NS_ASSUME_NONNULL_END
