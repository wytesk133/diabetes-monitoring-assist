//
//  MQSearchAheadResult.h
//  MapQuest
//
//  Copyright (c) 2018 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <MQCore/MQCore.h>

/// The result is an address
extern NSString * const MQSearchRecordTypeAddress;
/// The result is an airport
extern NSString * const MQSearchRecordTypeAirport;
/// The result is a city
extern NSString * const MQSearchRecordTypeCity;
/// The result is a County
extern NSString * const MQSearchRecordTypeCounty;
/// The result is a State
extern NSString * const MQSearchRecordTypeState;
/// The result is a Country
extern NSString * const MQSearchRecordTypeCountry;
/// The result is a neighborhood
extern NSString * const MQSearchRecordTypeNeighborhood;
/// The result is a postal code
extern NSString * const MQSearchRecordTypePostalCode;
/// The result is a Point of Interest
extern NSString * const MQSearchRecordTypePOI;
/// The result is a category
extern NSString * const MQSearchRecordTypeCategory;
/// The result is a franchise
extern NSString * const MQSearchRecordTypeFranchise;


/**
 The result from a search query
 */
@interface MQSearchAheadResult : NSObject

/**
 An index for the position this search item should show in the results
 */
@property(nonatomic, assign) NSUInteger positionInResults;
/**
 The sic code for this result. The sic code is returned for results from the category or franchise collection. You can use this code by doing a Place Search (using our search-api) to request results that have that code.
 */
@property(nonatomic, copy) NSString *placeQuery;
/**
 A string that contains a summary of the result that is returned. Depending on the type of result returned, the displayString could include a name, street, city, state, and postal code.
 */
@property(nonatomic, copy) NSString *displayString;
/**
 A string that contains the name of the result that is returned without additional summary information included.
 */
@property(nonatomic, copy) NSString *name;
/**
 A string that contains information about the type of result that is returned. Possible values are: airport, address, neighborhood, postalCode, city, county, state, country.
 */
@property(nonatomic, copy) NSString *recordType;
/**
 A array of strings that include the name of the collection or collections from which the result was served. Search Ahead organizes types of data into collections, which can be requested using this parameter. The following collections are currently supported: address, adminArea, airport, category, franchise, and poi.
 */
@property(nonatomic, copy) NSArray *collections;
/**
 A number that includes the a MapQuest-specific unique identifier, if applicable to the result. Generally returned with results served from the airport and poi collections. Please note: this response is now deprecated. Please use identifier.
 */
@property(nonatomic, readonly) NSString *mqId;
/**
 A string that includes the a MapQuest-specific unique identifier.
 */
@property(nonatomic, copy) NSString *identifier;
/**
 A string that contains a URL path fragment that will link to a specific address, admin area, or POI on MapQuest.com and may include additional information like reviews and business hours of operation if applicable to the type of result returned.
 */
@property(nonatomic, copy) NSString *slug;
/**
 A string that contains the ISO 639-1 language code of the result that is returned.
 */
@property(nonatomic, copy) NSString *language;
/**
 An object that describes the place by address and coordinates.
 */
@property(nonatomic, strong) MQPlace *place;

@end
