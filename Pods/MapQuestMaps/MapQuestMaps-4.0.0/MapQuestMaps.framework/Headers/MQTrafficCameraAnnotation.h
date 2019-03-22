//
//  MQTrafficCamera.h
//
//  Copyright (c) 2013 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Mapbox/Mapbox.h>

/**
 This class represents traffic camera annotations on the map
 */
@interface MQTrafficCameraAnnotation : NSObject<MGLAnnotation>

///Identification string for the annotation
@property(nonatomic, copy) NSString *idString;

///Latitude of the traffic camera.
@property(nonatomic, copy) NSDecimalNumber *lat;

///Longitude of the traffic camera
@property(nonatomic, copy) NSDecimalNumber *lng;

///Name of the caera
@property(nonatomic, copy) NSString *name;

///How often the camera view is updated
@property(assign) NSInteger updateFrequency;

///Direction the camera is facing (north, south, east, west)
@property(nonatomic, copy) NSString *view;

///URL for the latest screen capture of the camera
@property(nonatomic, copy) NSURL *cameraImageUrl;

@end
