//
//  SNCScanCodePlugin.h
//  SonectShop
//
//  Created by Marko Hlebar on 04/02/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^SNCScanCodeResultHandler)(NSString * _Nullable scanResult, NSError * _Nullable error);
@protocol SNCScanCodePlugin <NSObject>

- (UIViewController *)viewController;
- (void)scan:(SNCScanCodeResultHandler)handler;
- (void)stop;
@end

NS_ASSUME_NONNULL_END
