//
//  MQConstants.h
//  MapQuest
//
//  Created by Jason Sypher on 4/12/12.
//  Copyright (c) 2012 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif

// Historically, MQ has used 3963.205 mi (6378.160 km) as the earth's radius.
// However, this is larger than even the actual equitorial radius of
// 3963.190 mi (6378.137 km); The polar radius is 3949.903 mi (6356.7523 km).
// A median value for North America, at 37.5N = 3958.292 mi (6370.254 km),
// which seems the most accurate single value to use.
// See http://en.wikipedia.org/wiki/Earth_radius

// Use median values described above.
// They are only used in distance calculations (not in map projections)
#define EARTH_RADIUS_MILES 3958.292
#define EARTH_RADIUS_METERS 6370254.0


#define EPSILON 0.000001f

// Convenient conversions
#define KILOMETERS_PER_MILE 1.609344f
#define METERS_PER_KILOMETER 1000.0f
#define METERS_PER_MILE 1609.344f
#define METERS_PER_FOOT 0.3048f
#define MILES_PER_METER 0.000621371192f
#define METERS_PER_YARD 0.9144f
#define YARDS_PER_METER 1.093613298337708f

#define RADIANS_PER_DEGREE (M_PI/180.0)
#define DEGREES_PER_RADIAN (180.0/M_PI)
