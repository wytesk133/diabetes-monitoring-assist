//
//  MQManeuver.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MQNavigation/MQNavigationUnits.h>

@class MQLaneInfo;

/**
 Maneuver types
 */
typedef NS_ENUM(NSInteger, MQManeuverType) {
    /// No direction indicated
    MQManeuverType_NoDirectionIndicated = 0,
    /// Straight
    MQManeuverType_Straight = 1,
    /// Slight right
    MQManeuverType_SlightRight,
    /// Right
    MQManeuverType_Right,
    /// Sharp right
    MQManeuverType_SharpRight,
    /// Sharp left
    MQManeuverType_SharpLeft,
    /// Left
    MQManeuverType_Left,
    /// Slight left
    MQManeuverType_SlightLeft,
    /// Left u-turn
    MQManeuverType_LeftUturn,
    /// Right u-turn
    MQManeuverType_RightUturn,
    /// Right merge
    MQManeuverType_RightMerge,
    /// Left merge
    MQManeuverType_LeftMerge,
    /// Merge
    MQManeuverType_Merge,
    /// Right on ramp
    MQManeuverType_RightOnRamp,
    /// Left on ramp
    MQManeuverType_LeftOnRamp,
    /// Right off ramp
    MQManeuverType_RightOffRamp,
    /// Left off ramp
    MQManeuverType_LeftOffRamp,
    /// Right fork
    MQManeuverType_RightFork,
    /// Left fork
    MQManeuverType_LeftFork,
    /// Straight fork
    MQManeuverType_StraightFork,
    /// Reached destination
    MQManeuverType_Destination,
    /// Start driving on the route
    MQManeuverType_Start,
    /// Enter roundabout
    MQManeuverType_EnterRoundabout,
    /// Exit roundabout
    MQManeuverType_ExitRoundabout
};

/**
 An object containing information about maneuver
 */
@interface MQManeuver : NSObject

/**
 Position of the Maneuver on the route shape
 */
@property (readonly) MQNavigationRoutePosition position;

/**
 Name of the road that the maneuver leads to
 */
@property (nonnull, readonly) NSString *name;

/**
 Maneuver type
 */
@property (readonly) MQManeuverType type;

/**
 The lane information is not currently enabled on backend.
 
 Available and suggested maneuvers for all lanes in a road segment (bitwise OR'ed). For instance,
 if laneInfo.laneMarking values are [65, 65, 0, 4], there are four total lanes, and five available
 maneuvers, left or straight on the two leftmost lanes, and right on the rightmost lane;
 if laneInfo.laneHighlights values are [64, 64, 0, 0], there are four total lanes, and the two left
 lanes should be used to execute a left turn.
 65 = 0000 0100 0001
 64 = 0000 0100 0000
 4  = 0000 0000 0100
 */
@property (nullable, readonly) NSArray<MQLaneInfo*> *laneInfo;


/**
 Textual representation of the maneuver in the language specified in MQRouteOptions
 */
@property (nonnull, readonly) NSString *typeText;

@end
