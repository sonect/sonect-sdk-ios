//
//  NSURLRequest+SNCCurlDescription.h
//  Sonect
//
//  Created by Marko Hlebar on 18/07/2019.
//  Copyright © 2019 Sonect. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSURLRequest (SNCCurlDescription)

/**
 Return a curl command for debugging purposes.

 @return a cURL.
 */
- (NSString *)snc_curl;

@end

NS_ASSUME_NONNULL_END
