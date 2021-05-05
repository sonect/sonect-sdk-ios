//
//  SNCToken.h
//  Sonect
//
//  Created by Marko Hlebar on 10/12/2018.
//  Copyright © 2018 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNCToken : NSObject

/**
 Token value.
 */
@property (nonatomic, copy, readonly) NSString *value;

/**
 Token type, e.g. Bearer
 @default Bearer
 */
@property (nonatomic, copy, readonly) NSString *type;

/**
 Creates a token with value and type.

 @param value value
 @param type type
 @return a token.
 */
+ (instancetype)tokenWithValue:(NSString *)value type:(nullable NSString *)type;

/**
 Creates a token with value and type.

 @param value value
 @param type type
 @return a token.
 */
- (instancetype)initWithValue:(NSString *)value type:(nullable NSString *)type;

@end

NS_ASSUME_NONNULL_END
