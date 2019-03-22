//
//  MQPrompt.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MQNavigation/MQNavigationUnits.h>

/**
 Prompt placement enum that defines when the prompt should be played
 */
typedef NS_ENUM(NSInteger, MQPromptPlacement) {
    /// Unknown prompt placement
    MQPromptPlacementUnknown = -999999,
    /// Prompt should finish playing before the position on route
    MQPromptPlacementBefore = 0,
    /// Prompt should start playing after the position on route
    MQPromptPlacementAfter = 1
};

/**
 An object that describes the prompt for the next maneuver
 */
@interface MQPrompt : NSObject

/**
 Position of the prompt on the route
 */
@property (readonly) MQNavigationRoutePosition position;

/**
 What should be shown on the UI for the prompt
 */
@property (nonnull, readonly) NSString *text;

/**
 What should be spoken by the audio engine for the prompt
 */
@property (nonnull, readonly) NSString *speech;

/**
 Prompt placement enum that defines when the prompt should be played
 */
@property (readonly) MQPromptPlacement placement;

@end
