//
//  MQInstruction.h
//  MapQuest
//
//  Copyright (c) 2017 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MQNavigation/MQNavigationUnits.h>
#import <MQNavigation/MQManeuver.h>

/**
 This class simplifies creating lists of navigation instructions
 */
@interface MQInstruction : NSObject

/**
 Navigation instruction string. 
 
 @note This may be more verbose than the manuever text
 */
@property (nonnull, readonly) NSString *instruction;

/**
 Position of the instruction on the route
 */
@property (readonly) MQNavigationRoutePosition position;

/**
 Type of the maneuver that the instruction is associated with
 */
@property (readonly) MQManeuverType maneuverType;

/**
 Distance between previous maneuver and upcoming maneuver
 */
@property (readonly) CLLocationDistance distanceToManeuver;

@end
