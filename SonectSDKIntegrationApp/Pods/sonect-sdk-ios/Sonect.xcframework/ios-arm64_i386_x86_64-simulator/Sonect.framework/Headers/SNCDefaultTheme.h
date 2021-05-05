//
//  SNCDefaultTheme.h
//  Sonect
//
//  Created by Ivan Yanakiev on 13.04.21.
//  Copyright © 2021 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SNCTheme.h"

NS_ASSUME_NONNULL_BEGIN

@interface SNCDefaultTheme : SNCTheme

+ (instancetype)defaultThemeWithType:(SNCThemeType)themeType;

@end

NS_ASSUME_NONNULL_END
