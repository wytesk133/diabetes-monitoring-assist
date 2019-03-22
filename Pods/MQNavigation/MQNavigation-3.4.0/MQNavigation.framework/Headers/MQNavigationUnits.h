//
//  MQNavigationUnits.h
//  MQNavigation
//
//  Copyright © 2017 MapQuest. All rights reserved.
//


/**
 Enum to distinguish between different reasons that can stop navigation
 */
typedef NS_ENUM(NSUInteger, MQNavigationStoppedReason) {
    
    /// When navigation was cancelled
    MQNavigationStoppedReasonCancelled,
    
    /// When user reached destination and navigation was completed
    MQNavigationStoppedReasonCompleted
};

/**
 MQNavigationRoutePosition
 Type used to represent a position on route
 */
typedef double MQNavigationRoutePosition;

/**
 MQSpeedLimitType
    There are different kinds of speed limits
 */
typedef NS_ENUM(NSUInteger, MQSpeedLimitType) {
    
    /// Maximum posted speed limit
    MQSpeedLimitTypeMaximum = 0,
    
    /// Recommended speed limit
    MQSpeedLimitTypeRecommended,
    
    /// School zone speed limit
    MQSpeedLimitTypeSchoolZone
};

/**
 Measurement system type, like metric or imperial
 */
typedef NS_ENUM(NSInteger, MQSystemOfMeasurement) {
    
    /// Measurement system used in Liberia, Myanmar and USA
    MQSystemOfMeasurementImperial,
    
    /// Metric system of measurement
    MQSystemOfMeasurementMetric,
    
    /// Deprecated Measurement system used in Liberia, Myanmar and USA
    MQSystemOfMeasurementUnitedStatesCustomary __deprecated_enum_msg("Use MQSystemOfMeasurementImperial") = MQSystemOfMeasurementImperial
};
