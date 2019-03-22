//
//  CLLocation+Utils.h
//  guidance-ios
//
//  Created by jasonsypher06 on 11/30/15.
//  Copyright © 2015 Mapquest, Inc. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
@import CoreLocation;
#else
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#endif


@interface CLLocation(Utils)

- (CLLocationDirection)directionToLocation:(CLLocation*)location;
+ (CLLocationDirection) directionFromCoordinate:(CLLocationCoordinate2D)fromCoord toCoordinate:(CLLocationCoordinate2D) toCoord;
- (CLLocation*) newLocationAtDistance:(CLLocationDistance)distance toLocation:(CLLocation*)destination;

@end
