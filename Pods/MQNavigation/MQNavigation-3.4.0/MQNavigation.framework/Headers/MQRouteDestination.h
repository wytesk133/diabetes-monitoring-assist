//
//  MQRouteDestination.h
//  MQNavigation
//
//  Copyright © 2018 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
@import CoreLocation;

/**
 An protocol for an object passed to the MQRouteService that describes the destination with a required location coordinate and optional MQID
 */
@protocol MQRouteDestination <NSObject>
@required

/**
 The location of the destination. Used as a backup in case the MQID is empty or cannot be used.
 */
@property(nonatomic, nonnull, strong, readonly) CLLocation* location;

/**
 MQID of the destination. Provides the best-case routable destination.
 */
@property(nonatomic, nullable, strong, readonly) NSString *mqid;

@optional
/**
 Custom destination arrival radius. Useful for if you arriving to a city center, a stadium, or other large area.
 If used, some of our arrival logic may change.
 
 If the value is <=0, we will use the default arrival radius. The SDK may evaluate the radius against certain rules and elect to use it selectively.
 */
@property(nonatomic, readonly) CLLocationDistance arrivalAcceptanceRadius;

@end
