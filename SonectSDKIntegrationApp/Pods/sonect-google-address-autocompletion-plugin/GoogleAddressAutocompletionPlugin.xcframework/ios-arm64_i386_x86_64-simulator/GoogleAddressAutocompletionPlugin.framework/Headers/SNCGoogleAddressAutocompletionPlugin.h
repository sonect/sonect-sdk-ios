//
//  SNCGoogleAddressAutocompletionPlugin.h
//  SonectShop
//
//  Created by Ivan Yanakiev on 7.04.20.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//Marking a forward protocol helps fix the problem with imports.
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
@protocol SNCAddressAutocompletionPlugin;
@interface SNCGoogleAddressAutocompletionPlugin : NSObject <SNCAddressAutocompletionPlugin>
#pragma clang diagnostic pop

- (instancetype)initWithApiKey:(NSString *)apiKey;

@end

NS_ASSUME_NONNULL_END
