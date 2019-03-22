//
//  MQPlace.h
//  ios-core-model
//
//  Copyright (c) 2013 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif

#import <MQCore/MQAnnotation.h>
#import <MQCore/MQGeoAddress.h>

@interface MQPlace : NSObject <MQAnnotation, NSCoding, NSCopying>

/**
 **     Thinking of adding more properties?
 ** 
 **  Please think twice before you doing that. What you probably want is to add
 **  them to a subclass of MQPlace or to create a new subclass of MQPlace. 
 **  MQPlace will be our main object passed around and doesn't need any cruft.
 **/
@property (nonatomic, copy, nullable) MQGeoAddress* geoAddress;
@property (nonatomic, copy, nullable) NSString *title;
@property (nonatomic, copy, nullable) NSString *subtitle;
@property (nonatomic, readwrite) CLLocationCoordinate2D coordinate;
@property (nonatomic, readonly, nullable) NSString *mqid;

/** The `isNavigable` property always defaults to `YES` regardless
 *  of whether the place has a coordinate or a GeoAddress.
 *  It is currently intended to be used by consumers of MQPlace
 *  to mark places as non-navigable. It does not reflect anything
 *  about the quality of the GeoAddress or anything else.
 */
@property (nonatomic, assign) BOOL isNavigable;

-(BOOL)isEqualToPlace:(MQPlace*)place;

// Factory methods
+ (instancetype)placeFromGeoAddressDict:(NSDictionary*) geoDict;
+ (instancetype)placeFromGeoAddress:(MQGeoAddress*) geoAddress;

// The Designated initializer
- (instancetype)initWithGeoAddress:(MQGeoAddress *)geoAddress;

// Convienence Intializer
- (instancetype)initWithGeoAddressDict:(NSDictionary*)geoDict;
@end
