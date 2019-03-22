//
//  MQSpeedLimitSpan.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <MQNavigation/MQPositionSpan.h>

@class MQSpeedLimit;

/**
 An object that provides the speed limit for a span (a range of start/end position on a route)
 */
@interface MQSpeedLimitSpan : MQPositionSpan

/**
 Speed limit
 */
@property (nonnull, nonatomic, readonly) MQSpeedLimit *speedLimit;

@end
