//
//  SNCPresentationDelegate.h
//  Sonect
//
//  Created by Anton Iermilin on 26.08.2020.
//  Copyright © 2020 Sonect. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <SonectCore/SonectDefines.h>

NS_ASSUME_NONNULL_BEGIN

SNC_SWIFT_NAME(PresentationDelegate)
@protocol SNCPresentationDelegate <NSObject>

@optional

/**
Called on delegate when Sonect view controller is about to be dismissed.

@param sonectViewController sonect view controller.
*/
- (void)sonectViewControllerWillDismiss:(UIViewController *)sonectViewController;

/**
Called on delegate when Sonect view controller has been dismissed.

@param sonectViewController sonect view controller.
*/
- (void)sonectViewControllerDidDismiss:(UIViewController *)sonectViewController;

@end

NS_ASSUME_NONNULL_END
