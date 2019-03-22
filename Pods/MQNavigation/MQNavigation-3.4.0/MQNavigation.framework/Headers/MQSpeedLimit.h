//
//  MQSpeedLimit.h
//  MQNavigation
//
//  Copyright © 2017 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MQNavigation/MQNavigationUnits.h>
#import <CoreLocation/CoreLocation.h>

/**
 An object that describes the speed limit
 */
@interface MQSpeedLimit : NSObject

// TODO: should speed return MPH vs Meters based on MQSystemOfMeasurement?

/**
 Speed limit in meters/second
 */
@property (readonly) CLLocationSpeed speed;

/**
 Local system of measurement
 */
@property (readonly) MQSystemOfMeasurement localSystemOfMeasurement;

/**
 Speed limit type
 */
@property (readonly) MQSpeedLimitType speedLimitType;

@end
