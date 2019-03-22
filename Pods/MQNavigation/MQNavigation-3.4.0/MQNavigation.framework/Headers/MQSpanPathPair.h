//
//  MQSpanPathPair.h
//  MQNavigation
//
//  Copyright © 2017 MapQuest. All rights reserved.
//

#import <MQNavigation/MQPositionSpan.h>

@class MQLocationCoordinate2DArray;

/**
 An object that holds the span (start/end) and a part of a route shape
 */
@interface MQSpanPathPair : MQPositionSpan

/**
 Path array for the span on the route shape
 */
@property (nonnull, nonatomic, strong, readonly) MQLocationCoordinate2DArray *coordinateArray;

@end
