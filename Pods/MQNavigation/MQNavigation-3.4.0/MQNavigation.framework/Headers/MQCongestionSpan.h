//
//  MQCongestionSpan.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import "MQPositionSpan.h"

/**
  Traffic conditions along the route
 */
typedef NS_ENUM(NSInteger, MQCongestionSeverity) {
    /// Unknown traffic condition
    MQCongestionSeverityUnknown = -999999,
    /// Freeflowing traffic
    MQCongestionSeverityFreeFlow = 1,
    /// Slow moving traffic
    MQCongestionSeveritySlow = 2,
    /// Stop and go traffic
    MQCongestionSeverityStopAndGo = 3,
    /// Closed road
    MQCongestionSeverityClosed = 4
};

/**
 Position span along with traffic condition
 */
@interface MQCongestionSpan : MQPositionSpan

/**
 Traffic condition along the route for the span
 */
@property (readonly) MQCongestionSeverity severity;

@end
