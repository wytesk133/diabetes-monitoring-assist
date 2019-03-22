//
//  MQMapView.h
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Mapbox/MGLMapView.h>

@class MGLStyle;
@class MQNamedPlace;
@protocol MGLMapViewDelegate;
@protocol MQMapViewTrafficDelegate;
@protocol MQMapViewPOIDelegate;
/**
 Different map styles and types available
 */
typedef NS_ENUM(NSUInteger, MQMapType) {
    ///Normal map type.
    MQMapTypeNormal,
    ///Satellite view of the map
    MQMapTypeSatellite,
    ///Night mode/dark mode with darker color theme
    MQMapTypeNightMode
};


/**
 An interactive, customizable map view with an interface similar to the one
 provided by Apple’s MapKit.
 
 Using `MQMapView`, you can embed the map inside a view, allow users to
 manipulate it with standard gestures, animate the map between different
 viewpoints, and present information in the form of annotations and overlays.
 */
@interface MQMapView : MGLMapView


/// Delegate for configuring the appearance of traffic annotations and shapes
@property(nonatomic, weak, nullable) IBOutlet id<MQMapViewTrafficDelegate> trafficDelegate;

/// Delegate for Point Of Interest interactions
@property(nonatomic, weak, nullable) IBOutlet id<MQMapViewPOIDelegate> poiDelegate;

/**
 Configures whether traffic is currently displayed or not.
 */
@property (nonatomic, assign) BOOL trafficEnabled;

/**
 When trafficEnabled is YES, will display traffic flow data on map. Default is NO.
 */
@property (nonatomic, assign) BOOL shouldShowTrafficFlows;

/**
 When trafficEnabled is YES, will display traffic incidents on map. Default is NO.
 */
@property (nonatomic, assign) BOOL shouldShowTrafficIncidents;

/**
 When trafficEnabled is YES, will display traffic cameras on map. Default is NO.
 */
@property (nonatomic, assign) BOOL shouldShowTrafficCameras;

/**
 List of traffic annotations currently on the map
 */
@property (nonatomic, readonly, nonnull) NSArray *trafficAnnotations;

/**
 Can toggle between standard and satellite view. See MQMapType.h for options.
 */
@property (nonatomic, assign) MQMapType mapType;

/**
 URL of the style currently displayed in the receiver.
 */
- (NSURL *)styleURL;

/**
 Setter for styleURL is not supported in the MapQuest SDK. You can not change the Style URL.
 */
- (void)setStyleURL:(NSURL *)styleURL NS_UNAVAILABLE;

/** logoView property is not supported in the MapQuest SDK. */
@property (nonatomic, readonly, nullable) UIImageView *logoView NS_UNAVAILABLE;

/** styleURL property is not supported in the MapQuest SDK. */
- (nonnull NSArray<NSURL *> *)bundledStyleURLs NS_UNAVAILABLE;

/** styleClasses is not supported in the MapQuest SDK. */
- (nonnull NSString *)styleClasses NS_UNAVAILABLE;

/** addStyleClass is not supported in the MapQuest SDK. */
- (void)addStyleClass:(nonnull NSString * __unused)styleClass NS_UNAVAILABLE;

@end



/**
 The `MQMapViewTrafficDelegate` protocol defines a set of optional methods that you
 can use to receive traffic-related update messages. Because many map operations
 require the `MQMapView` class to load data asynchronously, the map view calls
 these methods to notify your application when specific operations complete. The
 map view also uses these methods to request information about traffic annotations
 displayed on the map, such as the styles and interaction modes to apply to
 individual annotations.
 */
@protocol MQMapViewTrafficDelegate <NSObject>

@optional

/**
 Implement this method to mark a traffic annotation with a static image. If you want to mark a particular traffic annotation with an annotation view instead, omit this method or have it return nil for that annotation, then implement -mapView:viewForTrafficAnnotation:.
 
 Static annotation images use less memory and draw more quickly than annotation views. On the other hand, annotation views are compatible with UIKit, Core Animation, and other Cocoa Touch frameworks.

 @param mapView The map view that requested the annotation image.
 @param annotation The object representing the annotation that is about to be displayed.
 @return The annotation image object to display for the given annotation or nil if you want to display the default image or an annotation view.
 */
- (nullable MGLAnnotationImage *)mapView:(nonnull MGLMapView *)mapView imageForTrafficAnnotation:(nonnull id <MGLAnnotation>)annotation;


/**
 Implement this method to mark a traffic annotation with a view object. If you want to mark a particular traffic annotation with a static image instead, omit this method or have it return nil for that annotation, then implement -mapView:imageForAnnotation: instead.
 
 Annotation views are compatible with UIKit, Core Animation, and other Cocoa Touch frameworks. On the other hand, static annotation images use less memory and draw more quickly than annotation views.

 @param mapView The map view that requested the annotation view.
 @param annotation The object representing the annotation that is about to be displayed.
 @return The view object to display for the given annotation or nil if you want to display an annotation image instead.
 */
- (nullable MGLAnnotationView *)mapView:(nonnull MGLMapView *)mapView viewForTrafficAnnotation:(nonnull id <MGLAnnotation>)annotation;


/**
 Returns the line width in points to use when rendering the outline of a traffic polyline annotation.
 By default, the polyline is outlined with a line 4.0 points wide.

 @param mapView mapView descriptionThe map view rendering the traffic annotation.
 @param annotation The annotation being rendered.
 @return A line width for the traffic polyline, measured in points.
 */
- (CGFloat)mapView:(nonnull MGLMapView *)mapView lineWidthForTrafficPolylineAnnotation:(nonnull MGLPolyline *)annotation;


/**
 Returns the color to use when rendering the outline of a shape annotation.
 
 Opacity may be set by specifying an alpha component. The default alpha value is 1.0 and results in a completely opaque stroke.

 @param mapView The map view rendering the traffic annotation.
 @param annotation The annotation being rendered.
 @return A color to use for the traffic annotation.
 */
- (nullable UIColor *)mapView:(nonnull MGLMapView *)mapView strokeColorForTrafficShapeAnnotation:(nonnull MGLShape *)annotation;

@end


/**
 The `MQMapViewPOIDelegate` protocol defines optional methods that you
 can use to receive a message when user interacts with Points of Interest.
 */
@protocol MQMapViewPOIDelegate <NSObject>

@optional

/**
 This method will be called when a Point of Interest is tapped on the map.

 @param mapView mapView that captured the tap
 @param poi object of MQNamedPlace that gives information about the POI that was tapped
 */
- (void)mapView:(nonnull MGLMapView *)mapView didTapOnPOI:(MQNamedPlace *)poi;

@end

