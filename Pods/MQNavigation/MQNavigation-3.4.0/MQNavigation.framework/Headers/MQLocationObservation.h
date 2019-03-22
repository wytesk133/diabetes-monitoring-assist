//
//  MQLocationObservation.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CLLocation.h>
#import <MQNavigation/MQNavigationUnits.h>

@class MQSpeedLimitSpan;
@class MQRouteLeg;
@class CLLocation;

/**
 Information about position on the route
 */
@interface MQLocationObservation : NSObject

/**
 This is the raw GPS location received from Location Manager
 */
@property (nonnull, readonly) CLLocation *rawGPSLocation;

/**
 This is the snapped location on the route
 */
@property (nonnull, readonly) CLLocation *snappedLocation;

/**
 This is the closest position on the route to user's location
 */
@property (readonly) MQNavigationRoutePosition snappedPosition;

/**
 This is the current leg user is on
 */
@property (nonnull, readonly) MQRouteLeg *currentLeg;

/**
 This is the distance in meters from user's current location to position on route
 */
@property (readonly) CLLocationDistance distanceFromRawLocationToSnappedLocation;

/**
 How far away in meters is the user from upcoming maneuver
 */
@property (readonly) CLLocationDistance distanceToUpcomingManeuver;

/**
 Distance in meters between snappedPosition and destination position of current leg
 */
@property (readonly) CLLocationDistance remainingLegDistance;

/**
 If the user is off route or not
 */
@property (readonly) BOOL isOffRoute;

@end
