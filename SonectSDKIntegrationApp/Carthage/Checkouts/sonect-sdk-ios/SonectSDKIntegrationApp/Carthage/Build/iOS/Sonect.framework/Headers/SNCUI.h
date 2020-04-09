//
//  SNCUI.h
//  Sonect
//
//  Created by Marko Hlebar on 02/03/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SNCUINavigationItem.h"

NS_ASSUME_NONNULL_BEGIN

@interface SNCUI : NSObject
@property (nonatomic, nullable, readonly) SNCUINavigationItem *navigationItem;

/// Create a new ui instance.
+ (instancetype)ui;

/// Sets the navigation item.
/// @param navigationItem a navigation item.
/// @return a ui instance.
- (instancetype)uiBySettingNavigationItem:(SNCUINavigationItem *)navigationItem;

@end

NS_ASSUME_NONNULL_END
