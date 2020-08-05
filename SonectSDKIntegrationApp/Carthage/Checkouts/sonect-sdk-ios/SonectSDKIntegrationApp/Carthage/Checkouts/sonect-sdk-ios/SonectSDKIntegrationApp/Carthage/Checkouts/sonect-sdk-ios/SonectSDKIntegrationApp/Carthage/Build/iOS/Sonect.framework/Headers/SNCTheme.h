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
@property (class, nonatomic, readonly) SNCTheme *currentTheme;

/**
 The theme general type light / dark.
 */
@property (nonatomic) SNCThemeType type;

/**
 Detail colors.
 */
@property (nonatomic, nullable) UIColor *detailColor1;
@property (nonatomic, nullable) UIColor *detailColor2;
@property (nonatomic, nullable) UIColor *detailColor3;
@property (nonatomic, nullable) UIColor *detailColor4;
@property (nonatomic, nullable) UIColor *detailColor5;

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
 Navigation bar tint color.
 */
@property (nonatomic, nullable) UIColor *navigationBarTintColor;

/**
 The title image in the navigation bar.
 */
@property (nonatomic, nullable) UIImage *navigationBarTitleImage;

/**
 The color of back arrow button in the navigation bar.
 */
@property (nonatomic, nullable) UIColor *backButtonColor;

/**
 The color selected amount. For default denominations, order of colors in amount picker is as follows:
 0 - 20
 1 - 50
 2 - 100
 3 - 200
  
 If number of colors is less than number of denominations in amount picker, it falls back to default colors.
 */
@property (nonatomic, nullable) NSArray <UIColor *> *selectedAmountColors;

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
