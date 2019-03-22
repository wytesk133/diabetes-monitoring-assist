//
//  MQMath.h
//  ios-core-model
//
//  Copyright (c) 2013 MapQuest. All rights reserved.
//

static const double RADIUS_M = 6378137.0; // Radius of earth in meters (WGS-84)
static const double CIRCUMFERENCE  = 2 * M_PI * RADIUS_M;
static const double CIRCUMFERENCE2 = M_PI * RADIUS_M;
static const double INCHES_PER_METER = 39.37;
static const double DEGREES_TO_RADIANS = M_PI / 180.0;
static const double RADIANS_TO_DEGREES = 180.0f / M_PI;
static const double DEGREES_TO_METERS = DEGREES_TO_RADIANS * RADIUS_M;
static const double METERS_TO_DEGREES = 1.0 / DEGREES_TO_METERS;

static inline float sqr(float a) {
    return a * a;
}
