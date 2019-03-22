//
//  CLLocationManager+MQ.h
//  location-ios
//
//  Created by johnodwyer11 on 4/13/15.
//  Copyright (c) 2015 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import CoreLocation;
#else
#import <CoreLocation/CoreLocation.h>
#endif

extern NSString* MQLocationLocationFailedNotification;

@interface CLLocationManager (MQ)

+ (BOOL)locationIsAuthorized;
+ (CLLocation *)lastLocation;
+ (BOOL)shouldUpdateInBackground;
+ (void)setShouldUpdateInBackground:(BOOL)shouldUpdateInBackground;

@end
