//
//  SNCUINavigationBar.h
//  Sonect
//
//  Created by Marko Hlebar on 02/03/2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNCUINavigationItem : NSObject

@property (nonatomic, nullable, readonly) UIBarButtonItem *rightBarButtonItem;

/// Sets a right bar button item.
/// @param item an item.
/// @return a navigation item.
- (instancetype)navigationItemBySettingRightBarButtonItem:(UIBarButtonItem *)item;

@end

NS_ASSUME_NONNULL_END
