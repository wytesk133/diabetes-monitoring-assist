//
//  MQShape.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MQNavigation/MQNavigationUnits.h>

@class  MQLocationCoordinate2DArray;


/**
 An object that describes the shape of a specific route. Used to draw polylines as overlays on a map
 */
@interface MQShape : NSObject

/**
 Coordinate array count

 @return Coordinate array count
 */
- (NSUInteger)coordinateCount;

/**
 A C-style array of coordinates that defines route shape

 @return Pointer to the array
 */
- (CLLocationCoordinate2D *_Nonnull)coordinates;

/**
 Coordinate at a given Index on the route

 @param index Index on the route
 @return Coordinate at the index in route shape array
 */
- (CLLocationCoordinate2D)coordinateAtIndex:(NSUInteger)index;

/**
 Coordinate at a given position on the route

 @param position Position on the route
 @return location Coordinate of the position on the route
 */
- (CLLocationCoordinate2D)coordinateAtPosition:(MQNavigationRoutePosition)position;

/**
 Calculates distance from an index to an other index

 @param fromPosition From position
 @param toPosition To position
 @return distance
 */
- (CLLocationDistance)distanceFromPosition:(MQNavigationRoutePosition)fromPosition toPosition:(MQNavigationRoutePosition)toPosition;


/** Find the closest position on the route shape to a given coordinate
 @param coordinate Coordinate to start with
 @param handler Handler block that will be called synchronously with coordinate of closest point on the shape and position of the location on the shape array
 */
- (void) closestPositionOnRouteToCoordinate:(CLLocationCoordinate2D)coordinate handler:(void(^ _Nonnull )(CLLocationCoordinate2D closestCoordinate, MQNavigationRoutePosition closestPosition))handler;

@end
