//
//  MQMercatorProjection.h
//  ios-core-model
//
//  Copyright (c) 2013 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import CoreLocation;
#else
#import <CoreLocation/CoreLocation.h>
#endif

#import <MQCore/MQMath.h>
#import <MQCore/MQFoundation.h>

typedef struct MQDoublePoint {
    double x;
    double y;
} MQDoublePoint;

MQ_EXTERN MQDoublePoint MQDoublePointMake(double x, double y);

/*
 * These points are in world coordinates.
 */
MQ_EXTERN MQDoublePoint mercatorTransform(CLLocationCoordinate2D ll) __attribute((const));

MQ_EXTERN CLLocationCoordinate2D mercatorInverseTransform(MQDoublePoint p) __attribute((const));
