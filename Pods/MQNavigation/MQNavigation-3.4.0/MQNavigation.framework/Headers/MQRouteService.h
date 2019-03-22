//
//  MQRouteService.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MQNavigation/MQTrafficOverview.h>

@class MQRoute;
@class MQRouteOptions;
@class MQTraffic;
@class MQEstimatedTimeOfArrival;
@class CLLocation;
@class MQCongestionSpan;
@protocol MQRouteDestination;

/// When requestRouteSummaryWithStartLocation:destination:completion: returns an error via parameter in the completion block, routeLength contains MQInvalidDistance
extern CLLocationDistance MQInvalidDistance;

/**
 Completion block returning a set of routes or an error

 @param routeResponse optional Array of routes
 @param error optional Error object
 */
typedef void (^MQRouteResponseCompletionBlock)(NSArray<MQRoute *> * _Nullable routeResponse, NSError * _Nullable error);

/**
 An object that provides routes based on a starting point and set of locations, with options
 */
@interface MQRouteService : NSObject

/**
 Method to find out if there are any requests pending

 @return YES if there are pending network requests
 */
- (BOOL)hasPendingRouteRequests;

/**
 Attempts to get a route starting from first location to second location and then to third and so on using MQIDs
 This is the preferred method of requesting routes
 
 @param startLocation Starting location for the route
 @param destinations List of MQRouteDestination-compliant objects that describe the list of locations
 @param options Route options for route
 @param completion Completion block to run when response is received from the API
 */
- (void)requestRoutesWithStartLocation:(nonnull CLLocation *)startLocation
                          destinations:(nonnull NSArray<id<MQRouteDestination>> *)destinations
                               options:(nonnull MQRouteOptions *)options
                            completion:(nonnull MQRouteResponseCompletionBlock) completion;

/**
 Attempts to get a route starting from first location to second location and then to third and so on
 
 @param startLocation Starting location for the route
 @param destinationLocations List of locations for destinations
 @param options Route options for route
 @param completion Completion block to run when response is received from the API
 */
- (void)requestRoutesWithStartLocation:(nonnull CLLocation *)startLocation
                  destinationLocations:(nonnull NSArray<CLLocation *> *)destinationLocations
                               options:(nonnull MQRouteOptions *)options
                            completion:(nonnull MQRouteResponseCompletionBlock) completion;


/**
 Cancels any pending route requests
 */
- (void)cancelRouteRequests;

/**
 Cancels any pending traffic/eta requests
 */
- (void)cancelPendingTrafficRequests;

/**
 Cancels any pending route summary requests
 */
- (void)cancelRouteSummaryRequests;

/**
 Completion block returning an optimized route summary from the requestRouteSummaryWithStartLocation method.
 
 @param estimatedTimeOfArrival optional Estimated Time of Arrival
 @param trafficConditions optional Traffic conditions. Set to MQTrafficOverviewUnknown if unknown.
 @param routeLength The route length
 @param error optional Error object
 */
typedef void (^MQSummaryResponseCompletionBlock)(MQEstimatedTimeOfArrival *estimatedTimeOfArrival, MQTrafficOverview trafficConditions, CLLocationDistance routeLength, NSError * _Nullable error);

/**
 Attempts to get an optimized route summary including ETA, traffic conditions, and route length.
 This method uses the fastest route to the provided destination from a starting location.
 
 Use this as the fastest way to get ETAs of the destination provided.
 
 @param startLocation Starting location for the route
 @param destination MQRouteDestination-compliant object that describes location
 @param completion Completion block to run when response is received from the API
 */
- (void)requestRouteSummaryWithStartLocation:(nonnull CLLocation *)startLocation
                                 destination:(nonnull id<MQRouteDestination>)destination
                                  completion:(nonnull MQSummaryResponseCompletionBlock)completion;

@end
