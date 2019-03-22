//
//  MQNavigationManager.h
//  MapQuest
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol MQNavigationManagerPromptDelegate;
@protocol MQNavigationManagerDelegate;

@class MQRoute;
@class MQRouteLeg;

/**
 State of the Navigation Manager at any point of time.
 */
typedef NS_ENUM(NSInteger, MQNavigationManagerState) {
    
    /// State where navigation manager is stopped or not navigating
    MQNavigationManagerStateStopped,
    
    /// State where navigation manager is actively navigating
    MQNavigationManagerStateNavigating,
    
    /// State where navigation manager is paused
    MQNavigationManagerStatePaused
};

/**
 State of the user consent for location tracking
 */
typedef NS_ENUM(NSInteger, MQUserLocationTrackingConsentStatus) {
    
    /// State where user location tracking consent is undefined. Navigation cannot be started in this state
    MQUserLocationTrackingConsentStatusAwaiting,
    
    /// State where user granted permission for location tracking
    MQUserLocationTrackingConsentStatusGranted,
    
    /// State where user denied permission for location tracking
    MQUserLocationTrackingConsentStatusDenied,
};

/**
 The central object for managing Navigation-related activities for your app
 */
@interface MQNavigationManager : NSObject


/**
 The object that acts as the prompt delegate of the navigation manager
 The delegate must adopt the MQNavigationManagerPromptDelegate protocol. The delegate is not retained.
 */
@property(nullable, nonatomic, weak) NSObject<MQNavigationManagerPromptDelegate> *promptDelegate;

/**
 The object that acts as the delegate of the navigation manager
 The delegate must adopt the MQNavigationManagerDelegate protocol. The delegate is not retained.
 */
@property(nullable, nonatomic, readonly, weak) NSObject<MQNavigationManagerDelegate> *delegate;

/**
 The current route that the navigation manager has and is navigating on
 */
@property(nullable, readonly) MQRoute *route;

/**
 Method to check if the navigation manager is stopped or not

 @return boolean Value representing whether the navigation manager is stopped or not
 */
@property(readonly) BOOL isStopped DEPRECATED_MSG_ATTRIBUTE("Deprecated in 3.2.0; Use -navigationManagerState instead ");

/**
 Method to check the state of navigation manager
 */
@property(readonly) MQNavigationManagerState navigationManagerState;

/**
 Returns current route leg the user is on
 
 @returns current leg
 */
@property(nullable, readonly) MQRouteLeg *currentRouteLeg;

/**
 Users must be prompted to provide consent for location tracking.
 A MQUserLocationTrackingConsentStatus of either Granted or Denied must be set before navigation can start.
 A MQUserLocationTrackingConsentStatus of Awaiting is not allowed to be set (protected by assertion)
 */
@property(nonatomic) MQUserLocationTrackingConsentStatus userLocationTrackingConsentStatus;

/**
 Init method to create instance of MQNavigationManager
 
 @param delegate object that conforms to MQNavigationManagerDelegate. Navigation manager will use this object to communicate with the host app.
 @param promptDelegate object that conforms to MQNavigationManagerPromptDelegate. Navigation manager will use this object to communicate with the host app
 @return instance of MQNavigationManager
 */
- (nullable instancetype)initWithDelegate:(nonnull NSObject<MQNavigationManagerDelegate> *)delegate promptDelegate:(nullable NSObject<MQNavigationManagerPromptDelegate> *)promptDelegate NS_DESIGNATED_INITIALIZER;

/**
 This method is unavailable. Use initWithDelegate:promptDelegate: instead

 @return nothing; this method is unavailable
 */
+ (instancetype _Nonnull)new __attribute((unavailable("Please use initWithDelegate:promptDelegate:")));


/**
 This method is unavailable. Use initWithDelegate:promptDelegate: instead
 
 @return nothing; this method is unavailable
 */
- (instancetype _Nonnull )init  __attribute((unavailable("Please use initWithDelegate:promptDelegate:")));

/**
 Starts navigation along the supplied route. MQNavigationManager may need to make additional service requests in order to actually begin navigation.  As a result, don't consider navigation to be started until the delegate has received a `navigationManagerDidStartNavigation:` call.

 @param route object of type MQRoute
 */
- (void)startNavigationWithRoute:(nonnull MQRoute *)route;

/**
 Stops navigation and resets all navigation state
 */
- (void)cancelNavigation;

/**
 Pauses the navigation. call resumeNavigation when ready to resume.
 */
- (void)pauseNavigation;

/**
 Resumes the navigation from paused state.
 
 @warning This method should be called only after pausing navigation.
 */
- (void)resumeNavigation;

/**
 Advances to the next leg of a multi-stop route. On a single destination route, does nothing.
 
 @warning This method should be called only during the `navigating` or `paused` state.
 @return Returns if advancing was successful
 */
- (BOOL)advanceRouteToNextLeg;

@end
