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

NS_ASSUME_NONNULL_BEGIN

typedef NSString *SNCDDLoggerName NS_TYPED_EXTENSIBLE_ENUM;

FOUNDATION_EXPORT SNCDDLoggerName const SNCDDLoggerNameOS NS_SWIFT_NAME(SNCDDLoggerName.os); // SNCDDOSLogger
FOUNDATION_EXPORT SNCDDLoggerName const SNCDDLoggerNameFile NS_SWIFT_NAME(SNCDDLoggerName.file); // SNCDDFileLogger

FOUNDATION_EXPORT SNCDDLoggerName const SNCDDLoggerNameTTY NS_SWIFT_NAME(SNCDDLoggerName.tty); // SNCDDTTYLogger

API_DEPRECATED("Use SNCDDOSLogger instead", macosx(10.4, 10.12), ios(2.0, 10.0), watchos(2.0, 3.0), tvos(9.0, 10.0))
FOUNDATION_EXPORT SNCDDLoggerName const SNCDDLoggerNameASL NS_SWIFT_NAME(SNCDDLoggerName.asl); // SNCDDASLLogger

NS_ASSUME_NONNULL_END
