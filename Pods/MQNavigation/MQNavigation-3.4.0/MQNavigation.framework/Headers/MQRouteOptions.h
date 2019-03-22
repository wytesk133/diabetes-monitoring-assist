//
//  MQRouteOptions.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MQNavigation/MQNavigationUnits.h>

/**
 Route options that we can send to the API
 */
typedef NS_ENUM(NSUInteger, MQRouteOptionType) {
    
    /// Enables something to be on routes
    MQRouteOptionTypeAllow,
    
    /// Does not guarantee that the type will be avoided if alternate route paths are too lengthy or not possible, or roads that contain these attributes are very short
    MQRouteOptionTypeAvoid,
    
    /// Guarantees that the type will be avoided as part of the route
    MQRouteOptionTypeDisallow
};


/**
 An object that describes the route options, such as avoiding toll/highways, given to the MQRouteService when requesting new routes
 */
@interface MQRouteOptions : NSObject

/**
 Allows: enable highways to be on route (default)
 Avoids: does not guarantee highways will be avoided if alternate route paths are too lengthy or not possible, or roads that contain these attributes are very short
 Disallows: guarantees highways will not be allowed as part of the route
 */
@property (nonatomic) MQRouteOptionType highways;

/**
 Allows: enable toll roads to be on route (default)
 Avoids: does not guarantee toll roads will be avoided if alternate route paths are too lengthy or not possible, or roads that contain these attributes are very short
 Disallows: guarantees toll roads will not be allowed as part of the route
 */
@property (nonatomic) MQRouteOptionType tolls;

/**
 Allows: enable ferries to be on route (default)
 Avoids: does not guarantee ferries will be avoided if alternate route paths are too lengthy or not possible, or roads that contain these attributes are very short
 Disallows: guarantees ferries will not be allowed as part of the route
 */
@property (nonatomic) MQRouteOptionType ferries;

/**
 Allows: enable unpaved roads to be on route (default)
 Avoids: does not guarantee unpaved roads will be avoided if alternate route paths are too lengthy or not possible, or roads that contain these attributes are very short
 Disallows: guarantees unpaved roads will not be allowed as part of the route
 */
@property (nonatomic) MQRouteOptionType unpaved;

/**
 Allows: enable country crossing roads to be on route (default)
 Avoids: does not guarantee country crossing roads will be avoided if alternate route paths are too lengthy or not possible, or roads that contain these attributes are very short
 Disallows: guarantees country crossing roads will not be allowed as part of the route
 */
@property (nonatomic) MQRouteOptionType internationalBorders;

/**
 Allows: enable seasonal roads to be on route (default)
 Avoids: does not guarantee seasonal roads with these attributes will be avoided if alternate route paths are too lengthy or not possible, or roads that contain these attributes are very short
 Disallows: guarantees seasonal roads with these attributes will not be allowed as part of the route
 */
@property (nonatomic) MQRouteOptionType seasonalClosures;

/**
 The maximum number of different routes that will be returned in the response. The number of routes actually returned may be less than the maximum number of routes specified. 
 The default value for max routes is 3.
 */
@property (nonatomic) NSUInteger maxRoutes;

/**
 System of measurement for all the display texts. This will control if the prompts are in miles (feet) or kilometers.
 This doesn't affect pure (not part of a text) distances returned by navigation engine, which are always in the metric system.
 */
@property (nonatomic) MQSystemOfMeasurement systemOfMeasurementForDisplayText;

/**
 Language (locale) for routing prompts, nil defaults to en_US
 */
@property (nonatomic, copy, nullable) NSString *language;

/**
 Rally mode tells the MQRouteService to ignore ignore traffic, time restrictions, and road closures. This can be used for parades and car rallies or to plan a route without consideration for current conditions, but still including the current condition data.
 */
@property (nonatomic) BOOL rallyMode;


@end
