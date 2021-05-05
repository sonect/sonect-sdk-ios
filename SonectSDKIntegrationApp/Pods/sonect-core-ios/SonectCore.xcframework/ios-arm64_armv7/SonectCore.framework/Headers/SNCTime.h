//
//  SNCTime.h
//  SonectCore
//
//  Created by Ivan Yanakiev on 19.01.21.
//  Copyright © 2021 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const kZeroHour;

@interface SNCTime : NSObject

/// Constant zero time - "0000"
@property (class, readonly) SNCTime *zeroTime;

/// Constant invalid time - "9999". Returned when initial string is not in proper format
@property (class, readonly) SNCTime *invalidTime;

/// Initializing SNCTime, format supported are 4 digit string e.g  "1223", and 4 digit string with with ":" delimiter between hours and minutes e.h "12:23"
- (instancetype)initWithString:(NSString *)timeString;

/// Returns 4 digit string representation e.g. "1543"
- (NSString *)toString;

/// Returns 4 digit string with ":" delimiter between hours and minutes representation e.g. "15:43"
- (NSString *)formattedString;

/// Compares with another SNCTime, returns NSOrdereredAscending if current time is preceeding anotherTime
- (NSComparisonResult)compare:(SNCTime *)anotherTime;

@end

NS_ASSUME_NONNULL_END
