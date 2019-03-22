//
//  MQRouteSummaryResponse.h
//  MQNavigation
//
//  Created by Eduard Smetanin on 5/25/18.
//  Copyright © 2018 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MQRoute.h"
#import "MQEstimatedTimeOfArrival.h"

/**
 An object that describes the traffic, route length and ETA
 */
@interface MQRouteSummaryResponse : NSObject

/**
 Route length in meters
 */
@property (nonatomic, nullable) NSNumber *length;

/**
 Estimated time to destination in seconds
 */
@property (nonatomic) NSTimeInterval realTime;

/**
 Traffic severity
 */
@property (nonatomic) MQTrafficOverview trafficOverview;

/**
 Estimated time of arrival
 */
@property (nonatomic, nullable) MQEstimatedTimeOfArrival *estimatedTimeOfArrival;

@end
