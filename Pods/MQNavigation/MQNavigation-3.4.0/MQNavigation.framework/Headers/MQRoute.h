//
//  MQRoute.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MQNavigation/MQTrafficOverview.h>

@class MQRouteLeg;
@class MQRouteOptions;
@class CLLocation;
@protocol MQRouteDestination;


/**
 An object that describes the route provided from the MQNavigationManager
 */
@interface MQRoute : NSObject


/**
 ID of route
 */
@property (nonnull, readonly) NSString *routeId;

/**
 An array of MQRouteLeg objects representing the route
 */
@property (nonnull, readonly) NSArray<MQRouteLeg *> *legs;

/**
 Route options used while getting route from the API
 */
@property (nonnull, readonly) MQRouteOptions *options;

/**
 Starting location sent to the API to get the route
 */
@property (nonnull, readonly) CLLocation *startingLocation;

/**
 List of destination locations
 */
@property (nonnull, readonly) NSArray<id<MQRouteDestination>> *destinations;

/**
 An overview of traffic in the route
 */
@property (readonly) MQTrafficOverview trafficOverview;

/**
 A name for the route. A route might have a name if it was one of the alternate routes
 */
@property (nonnull, readonly) NSString *name;


/**
 Deprecated List of destination locations
 */
@property (nonnull, readonly) NSArray<CLLocation*> *destinationLocations DEPRECATED_MSG_ATTRIBUTE("Use destinations instead");


@end
