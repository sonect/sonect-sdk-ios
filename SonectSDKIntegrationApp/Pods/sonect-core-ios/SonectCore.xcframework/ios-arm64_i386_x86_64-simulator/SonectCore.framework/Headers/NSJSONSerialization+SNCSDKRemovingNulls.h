//  NSJSONSerialization+SNCSDKRemovingNulls.h
//  Created by Richard Turton on 23/12/2013.

#import <Foundation/Foundation.h>

@interface NSJSONSerialization (SNCSDKRemovingNulls)

/// As the base class method, but pass YES to remove nulls from containers, optionally ignoring those in arrays.
+(id)sncsdk_JSONObjectWithData:(NSData *)data options:(NSJSONReadingOptions)opt error:(NSError *__autoreleasing *)error removingNulls:(BOOL)removingNulls ignoreArrays:(BOOL)ignoreArrays;

@end

@interface NSMutableDictionary (SNCSDKRemovingNulls)

-(void)sncsdk_recursivelyRemoveNulls;
-(void)sncsdk_recursivelyRemoveNullsIgnoringArrays:(BOOL)ignoringArrays;

@end

@interface NSMutableArray (SNCSDKRemovingNulls)

-(void)sncsdk_recursivelyRemoveNulls;
-(void)sncsdk_recursivelyRemoveNullsIgnoringArrays:(BOOL)ignoringArrays;

@end
