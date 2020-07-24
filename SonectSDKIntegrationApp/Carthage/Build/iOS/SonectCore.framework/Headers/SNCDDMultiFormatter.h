// Software License Agreement (BSD License)
//
// Copyright (c) 2010-2020, Deusty, LLC
// All rights reserved.
//
// Redistribution and use of this software in source and binary forms,
// with or without modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
//
// * Neither the name of Deusty nor the names of its contributors may be used
//   to endorse or promote products derived from this software without specific
//   prior written permission of Deusty, LLC.

#import <Foundation/Foundation.h>

// Disable legacy macros
#ifndef SNCDD_LEGACY_MACROS
    #define SNCDD_LEGACY_MACROS 0
#endif

#import <SonectCore/SNCDDLog.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * This formatter can be used to chain different formatters together.
 * The log message will processed in the order of the formatters added.
 **/
@interface SNCDDMultiFormatter : NSObject <SNCDDLogFormatter>

/**
 *  Array of chained formatters
 */
@property (nonatomic, readonly) NSArray<id<SNCDDLogFormatter>> *formatters;

/**
 *  Add a new formatter
 */
- (void)addFormatter:(id<SNCDDLogFormatter>)formatter NS_SWIFT_NAME(add(_:));

/**
 *  Remove a formatter
 */
- (void)removeFormatter:(id<SNCDDLogFormatter>)formatter NS_SWIFT_NAME(remove(_:));

/**
 *  Remove all existing formatters
 */
- (void)removeAllFormatters NS_SWIFT_NAME(removeAll());

/**
 *  Check if a certain formatter is used
 */
- (BOOL)isFormattingWithFormatter:(id<SNCDDLogFormatter>)formatter;

@end

NS_ASSUME_NONNULL_END
