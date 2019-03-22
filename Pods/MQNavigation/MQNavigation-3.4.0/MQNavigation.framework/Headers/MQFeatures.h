//
//  MQFeatures.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MQSpeedLimitSpan;

/**
 Container of maximum, recommended and school zone collections of speed limit spans
 */
@interface MQFeatures : NSObject

/**
 An array of speed limit spans representing maximum or posted speed limits
 */
@property (nonnull, readonly) NSArray<MQSpeedLimitSpan *> *maximumSpeedLimits;

/**
 An array of speed limit spans recommended speed limits
 */
@property (nonnull, readonly) NSArray<MQSpeedLimitSpan *> *recommendedSpeedLimits;

/**
 An array of speed limit spans representing school zone speed limits
 */
@property (nonnull, readonly) NSArray<MQSpeedLimitSpan *> *schoolZoneSpeedLimits;

/**
 Helper property that consolidates all speed limits into one array
 */
@property (nonnull, readonly) NSArray <MQSpeedLimitSpan *> *allSpeedLimits;

@end
