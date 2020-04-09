//
//  SNCPaymentContext.h
//  SonectSDK
//
//  Created by Marko Hlebar on 16/05/2019.
//  Copyright © 2019 Sonect. All rights reserved.
//

#ifndef SNCPaymentContext_h
#define SNCPaymentContext_h

typedef NS_ENUM(NSUInteger, SNCPaymentContext) {
    SNCPaymentContextUnknown = 0,
    SNCPaymentContextWithdraw = 1,
    SNCPaymentContextSendCash = 2
};

#endif /* SNCPaymentContext_h */
