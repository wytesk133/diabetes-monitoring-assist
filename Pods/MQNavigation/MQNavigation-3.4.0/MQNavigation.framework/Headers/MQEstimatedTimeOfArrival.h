//
//  MQEstimatedTimeOfArrival.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Describes ETA (Estimated Time of Arrival)
 */
@interface MQEstimatedTimeOfArrival : NSObject

/**
 ETA (Estimated Time of Arrival) at the destination
 */
@property (nullable, readonly) NSDate *time;

@end
