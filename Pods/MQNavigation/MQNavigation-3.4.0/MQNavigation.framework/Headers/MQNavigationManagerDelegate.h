//
//  MQNavigationManagerDelegate.h
//  MQNavigation
//
//  Copyright © 2017 MapQuest. All rights reserved.
//

@class MQRoute;
@class MQLocationObservation;
@class MQEstimatedTimeOfArrival;
@class MQTraffic;
@class MQRouteOptions;
@class MQPrompt;
@class MQSpeedLimitSpan;
@class MQSpeedLimit;
@class MQNavigationManager;

/**
 Callback to MQNavigationManager to accept that we've reached a destination
 
 @param didArrive Accept the arrival of the destination. If accepted the NavigationManager will continue to the next destination or if reaching the final destination, stop navigation
 */
typedef void (^MQConfirmArrivalBlock)(BOOL didArrive);

/**
 The MQNavigationManagerDelegate protocol defines the methods that a delegate of an MQNavigationManager object can implement to handle events specific to navigation
 */
@protocol MQNavigationManagerDelegate <NSObject>

@required

/**
 Called after attempting to start navigation, but encountering an error
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param error An NSError object describing the error
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager failedToStartNavigationWithError:(nonnull NSError*)error;

@optional

/**
 Called after starting navigation
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 */
- (void)navigationManagerDidStartNavigation:(nonnull MQNavigationManager *)navigationManager;

/**
 Called when navigation is stopped
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param navigationStoppedReason Reason navigation was stopped
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager stoppedNavigation:(MQNavigationStoppedReason)navigationStoppedReason;


/**
 Called when the navigation manager is paused
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 */
- (void)navigationManagerDidPauseNavigation:(nonnull MQNavigationManager *)navigationManager;

/**
 Called when the navigation manager is resumed
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 */
- (void)navigationManagerDidResumeNavigation:(nonnull MQNavigationManager *)navigationManager;


/**
 Called when the user crosses a border of speed limit span\s
 
 @note This method can be called with null parameters. At least one of the parameters will not be null
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param exitedSpeedLimits List of speed limit spans that the user exited
 @param enteredSpeedLimits List of speed limit spans that the user entered
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager crossedSpeedLimitBoundariesWithExitedZones:(nullable NSSet <MQSpeedLimit *> *)exitedSpeedLimits enteredZones:(nullable NSSet <MQSpeedLimit *> *)enteredSpeedLimits;


/**
 Called when the upcoming maneuver has been updated. This is called when the user goes past a maneuver
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param upcomingManeuver Upcoming maneuver in the list of maneuvers in current routeleg
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager didUpdateUpcomingManeuver:(nonnull MQManeuver *)upcomingManeuver;

/**
 Called when navigation is running and a new location has been delivered
 
 @warning This is called very often. Do not do anything processor intensive in this method
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param locationObservation Contains raw GPS location and snapped location on the route
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager receivedLocationObservation:(nonnull MQLocationObservation *)locationObservation;

/**
 Called when navigation is running and a new location with bad accuracy has been delivered.
 
 @note a location update with horizontal accuracy more than 100m is not accurate enough to be used for turn-by-turn navigation.
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param location Raw GPS location with bad accuracy
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager receivedInaccurateObservation:(nonnull CLLocation *)location;


/**
 Called when a destination has been reached (this can be a destination along a multipoint route).
 
 @warning If not implemented we assume the acceptance is true.
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param routeDestination The Destination object that was reached, conforming to MQRouteDestination
 @param completedRouteLeg The route leg that was just completed
 @param isFinalDestination If we have reached the final leg of the route
 @param confirmArrival Required callback to accept reaching the destination. If accepted the NavigationManager will continue to the next destination or if reaching the final destination, stop navigation
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager reachedDestination:(nonnull id<MQRouteDestination>)routeDestination forRouteLeg:(nonnull MQRouteLeg *)completedRouteLeg isFinalDestination:(BOOL)isFinalDestination confirmArrival:(nonnull MQConfirmArrivalBlock)confirmArrival;

/**
 Deprecated: use navigationManager:reachedDestination:forRouteLeg:isFinalDestination:confirmArrival instead
 Called when a destination has been reached (this can be a destination along a multipoint route).
 
 @warning If not implemented we assume the acceptance is true.
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param completedRouteLeg The route leg that was just completed
 @param isFinalDestination If we have reached the final leg of the route
 @param confirmArrival Required callback to accept reaching the destination. If accepted the NavigationManager will continue to the next destination or if reaching the final destination, stop navigation
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager reachedDestinationForRouteLeg:(nonnull MQRouteLeg *)completedRouteLeg isFinalDestination:(BOOL)isFinalDestination confirmArrival:(nonnull MQConfirmArrivalBlock)confirmArrival DEPRECATED_MSG_ATTRIBUTE("use navigationManager:reachedDestination:forRouteLeg:isFinalDestination:confirmArrival instead");

/**
 Called when we have detected a situation where a reroute should happen.
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 
 @return return a bool to indicate whether navigation manager should reroute or not
 
 @warning if this method is not implemented, NavigationSDK will go ahead and reroute
 */
- (BOOL)navigationManagerShouldReroute:(nonnull MQNavigationManager *)navigationManager;

/**
 Called when we have detected a situation where a reroute should happen
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 */
- (void)navigationManagerWillReroute:(nonnull MQNavigationManager *)navigationManager;

/**
 Called after a new route has been provided after a reroute
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param route New route that the navigation manager is using
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager didReroute:(nonnull MQRoute *)route;

/**
 Called when a failure happened whele we attempted a reroute
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param error Error details
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager failedToRerouteWithError:(nonnull NSError *)error;

/**
 Called when we attempted a reroute but the users current position would not work for the route we
 retrieved.  This can happen on slow networks.
 
 @note This can also happen if the user gets back on the original route when the reroute is received
 @param navigationManager NavigationManager object informing the delegate of this impending event
 */
- (void)navigationManagerDiscardedReroute:(nonnull MQNavigationManager *)navigationManager;

/**
 Called when we are going to check traffic conditions have changed
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 */
- (void)navigationManagerWillUpdateTraffic:(nonnull MQNavigationManager *)navigationManager;

/**
 Called when we have updated traffic conditions. Access it from navigationManager.currentRouteLeg.traffic
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param trafficByRouteLegId A dictionary that contains keys routeLegId and corresponding traffic
 */
- (void)navigationManagerDidUpdateTraffic:(nonnull MQNavigationManager *)navigationManager withTrafficByRouteLegId:(nonnull NSDictionary<NSString*/* route leg ID */,MQTraffic*> *)trafficByRouteLegId;

/**
 Called when we are going to check if the Estimated Time of Arrival is changed
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 */
- (void)navigationManagerWillUpdateETA:(nonnull MQNavigationManager *)navigationManager;

/**
 Called when we have updated ETA. You can access it from Access it from navigationManager.currentRouteLeg.traffic.estimatedTimeOfArrival
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 */
- (void)navigationManagerDidUpdateETA:(nonnull MQNavigationManager *)navigationManager withETAByRouteLegId:(nonnull NSDictionary<NSString*/* route leg ID */,MQEstimatedTimeOfArrival*> *)etaByRouteLegId;

/**
 Deprecated: use navigationManagerDidUpdateETA:withETAByRouteLegId: instead
 Called when we have updated ETA. You can access it from Access it from navigationManager.currentRouteLeg.traffic.estimatedTimeOfArrival
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 */
- (void)navigationManagerDidUpdateETA:(nonnull MQNavigationManager *)navigationManager withETA:(nonnull MQEstimatedTimeOfArrival *)eta DEPRECATED_MSG_ATTRIBUTE("use navigationManagerDidUpdateETA:withETAByRouteLegId: instead");

/**
 Called when a traffic update check has failed
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param error Error details
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager failedToUpdateTrafficWithError:(nonnull NSError *)error;

/**
 Called when a eta update check has failed
 
 @param navigationManager NavigationManager object informing the delegate of this impending event
 @param error Error details
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager failedToUpdateEtaWithError:(nonnull NSError *)error;

/**
 Called when we have a new route due to traffic. Developer is responsible for using the provided route and start navigating with new route
 
 @param navigationManager NavigationManager
 @param route An alternate Route to current route
 */
- (void)navigationManager:(nonnull MQNavigationManager *)navigationManager foundTrafficReroute:(nonnull MQRoute *)route;

/**
 Called when the app is in the background, device is running on battery, and the user has not moved out of the area in a period of time.
 You can react to this callback by bringing up a notification for the user to continue navigation, pausing navigation, or exiting
 
 @param navigationManager NavigationManager
 */
- (void)navigationManagerBackgroundTimerExpired:(nonnull MQNavigationManager *)navigationManager;
@end
