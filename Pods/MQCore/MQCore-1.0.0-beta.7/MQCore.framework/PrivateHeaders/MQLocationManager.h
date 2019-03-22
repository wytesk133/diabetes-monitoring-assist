//
//  MQLocationManager.h
//  navigation-ios
//
//  Created by David Gish on 8/5/13.
//  Copyright (c) 2013 Mapquest, Inc. All rights reserved.
//

#if __has_feature(modules)
@import CoreLocation;
#else
#import <CoreLocation/CoreLocation.h>
#endif

@class MQTripSimulator;
@class MQRoute;
@class MQNavigator;
@class MQLocation;

@interface MQLocationManager : CLLocationManager<CLLocationManagerDelegate>
@property (nonatomic, assign) BOOL useAutomotiveNavigationMode;
@property (nonatomic, copy) MQLocation*(^snapFilter)(MQLocation*);

+ (NSUInteger)instanceCount;
+ (void) setTripSimulator:(MQTripSimulator*)tripSimulator;
+ (void) lockSmoothCourseToCourse:(CLLocationDirection)course untilMoved:(CLLocationDistance)distance;

@end
