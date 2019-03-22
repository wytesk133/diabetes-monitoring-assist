//
//  MQGeoAddress.h
//  ios-core-model
//
//  Copyright (c) 2013 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import CoreLocation;
@import Foundation;
#else
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#endif

#import <MQCore/MQGeometry.h>

typedef NS_ENUM(NSUInteger, MQGeoQuality) {
    MQGQUnknown,
    MQGQSideOfStreet,
    MQGQAddress,
    MQGQStreet,
    MQGQIntersection,
    MQGQZip,
    MQGQCity,
    MQGQCounty,
    MQGQState,
    MQGQCountry,
    MQGQNeighborhood
};

/** A MQGeoAddress describes an address */
@interface MQGeoAddress : NSObject <NSCoding, NSCopying>

/** @name Properteis */

@property (nonatomic, copy) NSString *city;

/** Coordinate of this address - i.e. - possibly the last closeset point on a road to the address */
@property (nonatomic, assign) CLLocationCoordinate2D coordinate;

@property (nonatomic, copy) NSString *county;

@property (nonatomic, copy) NSString *country;

/** Coordinate off the road network - possibly roof top coordinate for this address */
@property (nonatomic, assign) CLLocationCoordinate2D displayCoordinate;

/** MQGeoQuality describes how accurate this MQGeoAddress is */
@property (nonatomic, assign) MQGeoQuality geoQuality;

/** The quality of the geocoded address 
 @see http://www.mapquestapi.com/geocoding/geocodequality.html
 */
@property (nonatomic, copy) NSString *qualityCode;

@property (nonatomic, copy) NSString* resultCode;

@property (nonatomic, copy) NSString *mqid;

@property (nonatomic, copy) NSString *neighborhood;

@property (nonatomic, copy) NSString *sideOfStreet;

@property (nonatomic, copy) NSString *state;

@property (nonatomic, copy) NSString *street;

/** The type of this address "s" means its a stop "v" means its a via point used in routing */
@property (nonatomic, copy) NSString *type;

@property (nonatomic, copy) NSString *zip;


/** @name Static Methods */

/** Utility method to generate strings based off the MQGeoQuality 
 @param quality MQGeoQuality 
 @return string representation of the MQGeoQuality
 */
+ (NSString *)stringForGeoQuality:(MQGeoQuality)quality;

/** Utility to take a string and return an MQGeoQuality
 @param geoQuality string to try to translate into a MQGeoQuality
 @return resolved MQGeoQuality
 */
+ (MQGeoQuality)geoQualityForString:(NSString*)geoQuality;


/** @name Methods */

- (NSString*) primaryString;

- (NSString*) secondaryString;

- (NSString*) singleLineString;

/** Determines equality based on singleLineString
 @param address to check equality against
 @return YES if singleLineString is equal
 */
- (BOOL)isEqualToAddress:(MQGeoAddress*)address;

/** @return a zoomLevel that is suitable applying to the map to show this MQGeoAddress */
-(NSUInteger)zoomLevelForGeoQuality;

/** Constructs a MQGeoAddress from a dictionary of values
 @param geoAddressDict dictionary of values
 @return MQGeoAddress loaded from dictionary
 */
+ (instancetype)geoAddressFromDictionary:(NSDictionary*) geoAddressDict;
@end
