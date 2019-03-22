//
//  MQCoordinateUtils.h
//  navigation-ios
//
//  Created by JohnO'Dwyer on 6/24/13.
//  Copyright (c) 2013 Mapquest, Inc. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
@import CoreLocation;
#else
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#endif

#import <MQCore/MQConstants.h>

@interface MQCoordinateUtils : NSObject

// Set all the accessible values from a CLLocation object, not just the lat/lon
//@property (nonatomic, retain)   CLLocation* location;

/**
 * Calculates the azimuth or bearing to the specified location (lat,lng).
 * @param    fromCoord   Coord to calculate the bearing from
 * @param    toCoord   Coord to calculate the bearing to
 * @return   Returns the bearing in degrees with range [0,360].
 */
+ (float) bearingFrom:(CLLocationCoordinate2D)fromCoord to:(CLLocationCoordinate2D)toCoord;

// Fastest; no trig, uses table lookup.
// Does not handle 180, -180 crossings. Since we only use this for short
// distances near or on a route, it should be totally adequate for most purposes.
+ (double) approximateDistanceFrom:(CLLocationCoordinate2D)fromCoord to:(CLLocationCoordinate2D)toCoord;

/**
 * Linear interpolation between 2 lat,lng positions.
 */
+ (CLLocationCoordinate2D) interpolateFrom:(CLLocationCoordinate2D)fromCoord to:(CLLocationCoordinate2D)toCoord percent:(float)percent;

/**
 * Find the closest coordinate along a segment. The algorithm works in lat,lng
 * space rather than miles or meters. Because of this it may not be exactly
 * correct (since distance in longitude varies based on latitude). However,
 * it should be reasonably correct. Actual distances should be computed
 * using the test lat,lng position and the closest point returned from
 * this method.
 *
 * @param coord the coordinate to check the line against
 * @param startingCoord the starting point of the line
 * @param endingCoord the ending point of the line
 *
 * @return      The closest coord on the line
 */
+ (CLLocationCoordinate2D) closestCoordToCoord:(CLLocationCoordinate2D)coord
                    alongLineWithStartingCoord:(CLLocationCoordinate2D)startingCoord
                                andEndingCoord:(CLLocationCoordinate2D)endingCoord;

+ (BOOL) coord:(CLLocationCoordinate2D)coord1 isEqualTo:(CLLocationCoordinate2D)coord2;
@end

#ifdef __cplusplus
extern "C" {
#endif
    static inline double toRadians(double degrees)
    {
        return degrees * RADIANS_PER_DEGREE;
    }
    
    static inline double toDegrees(double radians)
    {
        return radians * DEGREES_PER_RADIAN;
    }
    
    // Convenience function for distance squared based on dx, dy
    static inline double distSqr(double dx, double dy)
    {
        return dx * dx + dy * dy;
    }
	
    /**
     * @param miles Input of Miles
     *
     * @return meters
     */
    static inline double toMeters(double miles)
    {
        return miles * METERS_PER_MILE;
    }
    
    /**
     * @param meters Input of Meters
     *
     * @return miles
     */
    static inline double toMiles(double meters)
    {
        return meters / METERS_PER_MILE;
    }
    
#ifdef __cplusplus
}
#endif
