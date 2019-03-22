//
//  MQError.h
//  MQNavigation
//
//  Created by Alex Kac on 12/5/17.
//  Copyright © 2017 MapQuest. All rights reserved.
//

/**
 Error Domain for the MQNavigationFramework
 
 **/
extern NSString* const _Nonnull MQNavigationErrorDomain;


/**
 Error codes provided by MQNavigation
 */
typedef NS_ENUM(NSInteger, MQNavigationErrorCode) {
    
    /// Navigation Failed to start due to Location Manager Authorization Status
    MQNavigationErrorCodeDeniedLocationAuthorization,
    
    /// Internal error occurred
    MQNavigationErrorCodeInternalError,
    
    /// There are no more destinations for Navigation to route to
    MQNavigationErrorCodeDestinationsEmpty,
    
    /// Your Application Key is invalid
    MQNavigationErrorCodeApplicationKeyInvalid = 1000,
    
    /// Navigation received an error from the server
    MQNavigationErrorCodeServerError,
    
    /// Navigation tried to access servers but received a result that looked like a captive portal
    MQNavigationErrorCodeServerAccessDeniedWithCaptivePortal,
    
    /// Error contains the JSON received and the NSURLError
    MQNavigationErrorCodeNSURLError,

    /// Too many failures. For example if we have too many network errors in a row.
    MQNavigationErrorCodeTooManyFailures,
    
    /// Requested language is not a valid language
    MQNavigationErrorCodeInvalidLanguage,
    
    /// A reroute request failed due to returning no available routes
    MQNavigationErrorCodeRerouteFailedWithNoRoutes,
	
    /// Consent to track location was not set to either Granted nor Denied
    MQNavigationErrorCodeUserLocationTrackingConsentNotSet,

    /// This is an informational error. Our Route is invalid and we need to refresh it. The SDK will refresh the route automatically.
    MQNavigationErrorCodeRouteIsBeingRefreshed,
    
    /// A route summary request failed due to returning no available routes
    MQNavigationErrorCodeRouteSummaryFailedWithNoRoutes,
};
