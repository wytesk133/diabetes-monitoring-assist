//
//  MQSearchServiceV3.h
//  MapQuest
//
//  Copyright (c) 2018 MapQuest. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import <Foundation/Foundation.h>

@class MQSearchAheadResult;
@class MQSearchAheadResponse;
@class MQSearchAheadOptions;

NS_ASSUME_NONNULL_BEGIN

/// The Address Collection - will return results including building addresses
extern NSString * const MQSearchAheadCollectionAddress;
/// The Admin Area Collection - will return results including administration areas
extern NSString * const MQSearchAheadCollectionAdminArea;
/// The Airport Collection - will return results including airports
extern NSString * const MQSearchAheadCollectionAirport;
/// The Point of Interest Collection - will return results including Points of Interest - such as businesses, restaurants, stores, etc…
extern NSString * const MQSearchAheadCollectionPOI;
/// The Category Collection - will return a list of supported categories
extern NSString * const MQSearchAheadCollectionCategory;
/// The Franchise Collection - will return results including franchises
extern NSString * const MQSearchAheadCollectionFranchise;

/**
 The main MapQuest Search Ahead service object
 */
@interface MQSearchAheadService : NSObject

/**
 The search call *without* a geographic context

 @param query A query phrase. The phrase can be incomplete, in which case its last term is treated as a prefix during matching. Address queries must begin with a street number. Minimum 2 characters, maximum 100 characters
 @param collections The following collections are currently supported: MQSearchAheadCollectionAddress, MQSearchAheadCollectionAdminArea, MQSearchAheadCollectionAirport, MQSearchAheadCollectionPOI, MQSearchAheadCollectionCategory, and MQSearchAheadCollectionFranchise
 @param options An instance of MQSearchAheadOptions where you can set the language, result limit, and whether the results include feedback
 @param success A block that handles the search results
 @param failure A block that handles the failure of a search call
 */
- (void)predictResultsForQuery:(NSString *)query
                   collections:(NSArray *)collections
                       options:(nullable MQSearchAheadOptions*)options
                       success:(nullable void(^)(MQSearchAheadResponse * response))success
                       failure:(nullable void(^)(NSError *error))failure;

/**
 The search call with a geographic context

 @param query A query phrase. The phrase can be incomplete, in which case its last term is treated as a prefix during matching. Address queries must begin with a street number. Minimum 2 characters, maximum 100 characters
 @param collections The following collections are currently supported: MQSearchAheadCollectionAddress, MQSearchAheadCollectionAdminArea, MQSearchAheadCollectionAirport, MQSearchAheadCollectionPOI, MQSearchAheadCollectionCategory, and MQSearchAheadCollectionFranchise
 @param location The geographic context used for searching, ranking, and ordering results. Supports a point defining the geographic "center" of the query. While this parameter is not required, it is highly recommended that it be provided in order to improve relevance of results.
 @param options An instance of MQSearchAheadOptions where you can set the language, result limit, and whether the results include feedback
 @param success A block that handles the search results
 @param failure A block that handles the failure of a search call

 */
- (void)predictResultsForQuery:(NSString *)query
                   collections:(NSArray *)collections
                      location:(CLLocationCoordinate2D)location
                       options:(nullable MQSearchAheadOptions*)options
                       success:(nullable void(^)(MQSearchAheadResponse *response))success
                       failure:(nullable void(^)(NSError *error))failure;

/**
 Returns true or false if the search service is waiting on a response from the server

 @return return true or false
 */
- (BOOL)inFlight;

@end

NS_ASSUME_NONNULL_END
