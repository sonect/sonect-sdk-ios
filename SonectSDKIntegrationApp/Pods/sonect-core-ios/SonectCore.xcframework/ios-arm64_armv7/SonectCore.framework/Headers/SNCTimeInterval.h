//
//  SNCTimeInterval.h
//  SonectCore
//
//  Created by Ivan Yanakiev on 21.01.21.
//  Copyright © 2021 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SNCTime;

@interface SNCTimeInterval: NSObject

@property (nonatomic, copy, readonly) SNCTime *from;
@property (nonatomic, copy, readonly) SNCTime *to;

- (instancetype)initWithStringTimeFrom:(NSString *)from to:(NSString *)to;

- (instancetype)initWithTimeFrom:(SNCTime *)from to:(SNCTime *)to;

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

- (BOOL)isValid;
- (BOOL)isTimeInInterval:(SNCTime *)time;
- (BOOL)isHourInInterval:(NSString *)hour;

/// Returns true if time interval intersects this time interval
- (BOOL)intersectsTimeInterval:(SNCTimeInterval *)interval;

- (NSComparisonResult)compare:(SNCTimeInterval *)interval;

/// Returns period in format "hh:mm - hh:mm" e.g "08:50 - 12:00"
- (NSString *)formattedString;

@end

NS_ASSUME_NONNULL_END
