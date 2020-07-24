//
//  SNCSonectEventHandler.h
//  SonectSDK
//
//  Created by Ivan Yanakiev on 8.05.19.
//  Copyright © 2019 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class SNCSonect;

@protocol SNCSonectEventHandler <NSObject>

/**
 Inform event handler of occuring event.

 @param sonect a sonect instance.
 @param event occuring
 */
- (void)sonect:(SNCSonect *)sonect handleEvent:(NSString *)event withParameters:(NSDictionary  * _Nullable)parameters;

@end

NS_ASSUME_NONNULL_END
