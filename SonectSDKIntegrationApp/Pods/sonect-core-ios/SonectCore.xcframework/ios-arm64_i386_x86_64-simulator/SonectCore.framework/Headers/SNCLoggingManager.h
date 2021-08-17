//
//  SNCLoggingManager.h
//  Sonect
//
//  Created by Oleksandr Bedzyk on 16.07.2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SNCLogging.h"
#import "SNCDDLogMacros.h"

extern SNCDDLogLevel const ddLogLevel;

NS_ASSUME_NONNULL_BEGIN

@interface SNCLoggingManager : NSObject
+ (void)setupLoggers;
@end

NS_ASSUME_NONNULL_END
