//
//  MQLocationCoordinate2DArray.h
//  MQNavigation
//
//  Copyright © 2017 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 Wrapper class to hold a primitive (C style) type array and count of items in the array
 */
@interface MQLocationCoordinate2DArray : NSObject

/**
 An array of coordinates
 */
@property (nonnull, nonatomic, readonly) CLLocationCoordinate2D *coordinateArray;

/**
 Number of coordinates in the coordinateArray
 */
@property (nonatomic, assign) NSUInteger count;

/**
 Init method for the class

 @param locations Array of coordinates
 @return returns an instance of MQLocationCoordinate2DArray
 */
- (nonnull instancetype)initWithLocations:(nonnull NSArray<CLLocation *> *)locations NS_DESIGNATED_INITIALIZER;

/**
 We do not support init on this object

 @return nothing
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

@end
