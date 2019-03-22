//
//  MQLocation.h
//  MQiOS3
//
//  Created by David Gish on 11/7/11.
//  Copyright (c) 2011 MapQuest/AOL, LLC. All rights reserved.
//

#if __has_feature(modules)
@import CoreLocation;
#else
#import <CoreLocation/CoreLocation.h>
#endif

@interface MQLocation : CLLocation <NSCoding, NSCopying>
@property (nonatomic, readwrite) double  smoothSpeed;
@property (nonatomic, readwrite) double  smoothCourse;
@property (nonatomic, readwrite) BOOL    exceedsMovementLimit;
@property (nonatomic, readwrite) BOOL    significantChange;

-(id)initWithCLLocation:(CLLocation*)location;
-(BOOL)isEqualToLocation:(MQLocation*)location;
-(BOOL)isEqualToLocation:(MQLocation*)location withDelta:(double)delta;

@end
