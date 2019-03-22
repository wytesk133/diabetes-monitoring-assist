//
//  MQWebViewController.h
//  MQUtilities
//
//  Created by Mark Husson on 5/20/14.
//  Copyright (c) 2014 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import UIKit;
#else
#import <UIKit/UIKit.h>
#endif


@interface MQWebViewController : UIViewController

/**
 *  This is the toolbar used for web navigation. This property is accessable so you can 
 *  change it's appearance for use in your app
 */
@property (nonatomic, strong) UIToolbar *toolBar;

- (id) initWithUrl:(NSURL *)url;

@end
