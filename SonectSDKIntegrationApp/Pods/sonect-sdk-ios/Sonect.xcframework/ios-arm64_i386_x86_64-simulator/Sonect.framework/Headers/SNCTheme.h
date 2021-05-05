//
//  SNCTheme.h
//  Sonect
//
//  Created by Bruno Sousa on 21/12/2018.
//  Copyright © 2018 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const SNCThemeSystemFontName;
extern NSString * const SNCThemeBoldSystemFontName;

typedef NS_ENUM(NSUInteger, SNCThemeType) {
    SNCThemeTypeDark = 0,
    SNCThemeTypeLight,
};

@interface SNCTheme : NSObject

/**
 The currently applied theme.
 This gets populated when you -set the theme. If theme is not set, original Sonect theme will be used.
 */
@property (class, nonatomic, readonly, nonnull) SNCTheme *currentTheme;

/**
 The theme general type light / dark.
 */
@property (nonatomic) SNCThemeType type;

/**
 Background colors.
 */
@property (nonatomic, nullable) UIColor *backgroundColor1;
@property (nonatomic, nullable) UIColor *backgroundColor2;
@property (nonatomic, nullable) UIColor *backgroundColor3;
@property (nonatomic, nullable) UIColor *backgroundColor4;
@property (nonatomic, nullable) UIColor *backgroundColor5;
@property (nonatomic, nullable) UIColor *backgroundColor6;
@property (nonatomic, nullable) UIColor *backgroundColor7;

/**
 Info text colors.
 */
@property (nonatomic, nullable) UIColor *titleColor;
@property (nonatomic, nullable) UIColor *descriptionColor;

/**
 Icon colors.
 */
@property (nonatomic, nullable) UIColor *iconColor1;
@property (nonatomic, nullable) UIColor *iconColor2;
@property (nonatomic, nullable) UIColor *iconColor3;

/**
 Alert colors.
 */
@property (nonatomic, nullable) UIColor *alertTextColor1;
@property (nonatomic, nullable) UIColor *alertTextColor2;

/**
 Used to convey inline error state of action.
 */
@property (nonatomic, nullable) UIColor *alertTextColor3;

/**
 Status text colors.
 */
@property (nonatomic, nullable) UIColor *statusTextColor1;
@property (nonatomic, nullable) UIColor *statusTextColor2;
@property (nonatomic, nullable) UIColor *statusTextColor3;
@property (nonatomic, nullable) UIColor *statusTextColor4;

/**
 Brand colors.
 */
@property (nonatomic, nullable) UIColor *primaryColor1;
@property (nonatomic, nullable) UIColor *primaryColor2;
@property (nonatomic, nullable) UIColor *primaryColor3;
@property (nonatomic, nullable) UIColor *primaryColor4;
@property (nonatomic, nullable) UIColor *borderColor1;
@property (nonatomic, nullable) UIColor *borderColor2;

@property (nonatomic, nullable) UIColor *titleActiveColor;
@property (nonatomic, nullable) UIColor *phoneInfoColor;

/**
 The regular font name.
 @discussion to use system fonts, pass SNCThemeSystemFontName.
 */
@property (nonatomic, nullable) NSString *fontName;

/**
 The bold font name.
 @discussion to use system fonts, pass SNCThemeBoldSystemFontName.
 */
@property (nonatomic, nullable) NSString *boldFontName;

/**
 The shadow radius of navigation bar in light theme. .
 */
@property (nonatomic) CGFloat navigationBarShadowRadius;

/**
 Order of categories:
 0 - Kiosk
 1 - Supermarket
 2 - Bakery
 3 - Cafe
 4 - Restaurant
 5 - Pharmacy
 6 - Events
 7 - General
 */
@property (nonatomic, nullable) NSArray *mapCategoryImages;

/**
 Order of categories - default value:
 0 - Kiosk - "Kiosk"
 1 - Supermarket - "Supermarket"
 2 - Bakery - "Bakery"
 3 - Cafe - "Cafe"
 4 - Restaurant - "Eat&Drink"
 5 - Pharmacy - "Pharmacy"
 6 - Events - "Clubs&Events"
 7 - General - "Show all"
 */
@property (nonatomic, nullable) NSArray *mapCategoryDescriptions;

/**
 Sets the theme as currentTheme. You should do this as early as possible.
 */
- (void)set;

@end

NS_ASSUME_NONNULL_END
