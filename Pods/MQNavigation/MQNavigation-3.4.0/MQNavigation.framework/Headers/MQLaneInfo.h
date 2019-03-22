//
//  MQLaneInfo.h
//  MQNavigation
//
//  Copyright © 2017 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 The lane information is not currently enabled on backend.
 
 Maneuvers (possible or suggested) for the lane.
 */
typedef NS_ENUM(NSUInteger, MQLaneMarkingType) {
    /// Unknown
    MQLaneMarkingTypeUnknown = 0,
    /// Straight
    MQLaneMarkingTypeStraight = 1 << 0,
    /// Slight right
    MQLaneMarkingTypeSlightRight = 1 << 1,
    /// Right
    MQLaneMarkingTypeRight = 1 << 2,
    /// Sharp right
    MQLaneMarkingTypeSharpRight = 1 << 3,
    /// Right u-turn
    MQLaneMarkingTypeRightUTurn = 1 << 4,
    /// Slight left
    MQLaneMarkingTypeSlightLeft = 1 << 5,
    /// Left
    MQLaneMarkingTypeLeft = 1 << 6,
    /// Sharp Left
    MQLaneMarkingTypeSharpLeft = 1 << 7,
    /// Left u-turn
    MQLaneMarkingTypeLeftUTurn = 1 << 8,
};


/**
 The lane information is not currently enabled on backend.
 */
@interface MQLaneInfo : NSObject

/**
 The lane information is not currently enabled on backend.
 
 Available maneuvers for a lane in a road segment (bitwise OR'ed). For instance,
 if the property is equal to 65 (0000 0100 0001), it means left or straight maneuvers are possible for the lane;
 if the property is equal to 4 ( 0000 0000 0100), it means right turn is possible for the lane
 */
@property (readonly) NSUInteger laneMarking;

/**
 The lane information is not currently enabled on backend.
 
 Recommended (to stay on the route) maneuvers for a lane in a road segment (bitwise OR'ed). For instance,
 if the property is equal to 64 (0000 0100 0000), it means left turn is suggested for the lane
 */
@property (readonly) NSUInteger laneHighlights;

@end
