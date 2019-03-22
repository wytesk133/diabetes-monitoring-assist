//
//  MQTraffic.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MQCongestionSpan;
@class MQEstimatedTimeOfArrival;

/**
 An object that provides the ETA and traffic conditions for a specific route
 */
@interface MQTraffic : NSObject

/**
 A list of condition spans on the route
 */
@property (nonnull, readonly) NSArray<MQCongestionSpan *> *conditions;

/**
 ETA object
 */
@property (nonnull, readonly) MQEstimatedTimeOfArrival *estimatedTimeOfArrival;

@end
