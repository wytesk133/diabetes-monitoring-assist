//
//  MQRouteLeg.h
//  MQNavigation
//
//  Copyright © 2017 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@class MQPrompt;
@class MQFeatures;
@class MQManeuver;
@class MQTraffic;
@class MQShape;
@class MQCongestionSpan;
@class MQInstruction;


/**
 An object that describes the specific segment of a route to a single destination
 */
@interface MQRouteLeg : NSObject

/**
 An object that holds a list of coordinates that represent the route leg
 */
@property (nonnull, readonly) MQShape *shape;

/**
 Features include speed limits
 */
@property (nonnull, readonly) MQFeatures *features;

/**
 A list of maneuvers in the route leg
 */
@property (nonnull, readonly) NSArray<MQManeuver *> *maneuvers;

/**
 Id of the route leg
 */
@property (nonnull, readonly) NSString *routeLegId;

/**
 Lenth of the route in meters
 */
@property (readonly) CLLocationDistance length;

/**
 A list of prompts
 */
@property (nonnull, readonly) NSArray<MQPrompt *> *prompts;

/**
 Traffic congestion information on the route leg
 */
@property (nonnull, readonly) MQTraffic *traffic;

/**
 A list of navigation instructions. This is an amalgamation of prompts and maneuvers that can be easily shown as a list of instructions for navigation
 */
@property (nonnull, readonly) NSArray<MQInstruction *> *instructions;


@end
