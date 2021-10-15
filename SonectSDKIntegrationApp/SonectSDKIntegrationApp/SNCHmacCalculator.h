//
//  SNCHmacCalculator.h
//  Sonect
//
//  Created by Marko Hlebar on 04/07/2019.
//  Copyright © 2019 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SNCHmacCalculator
+ (NSString *)signatureWithParameters:(NSArray *)parameters key:(NSString *)key encodeKey:(BOOL)encodeKey;
@end

NS_ASSUME_NONNULL_END
