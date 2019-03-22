//
//  MQRoutePositionSpan.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MQNavigation/MQNavigationUnits.h>

/**
 Position span consisting of start and end positions.
 */
@interface MQPositionSpan : NSObject

/**
 Starting position of the span
 */
@property (readonly) MQNavigationRoutePosition start;

/**
 Ending position of the span
 */
@property (readonly) MQNavigationRoutePosition end;

@end
