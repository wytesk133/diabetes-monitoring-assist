//
//  MQSearchAheadFeedback.h
//  MapQuest
//
//  Copyright (c) 2018 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 MapQuest provides a feedback API that can be used to enhance the quality of the results returned from the Search Ahead API. This object is returned when `includesFeedback` is set in the MQSearchAheadOptions class. Usage of this service is optional, but if you wish to participate you will receive the resulting URLs which you can use when the item is displayed in a list or on a map, or when clicked.</p>
 
 Please visit https://developer.mapquest.com/documentation/searchahead-api/feedback/ for more information
 */
@interface MQSearchAheadFeedback : NSObject

/**
 If the results are displayed in a list or on a map, replace {/id*} with the IDs displayed in the corresponding URL resultClickedURL and POST to the resulting URL
 
 Example: http://www.mapquestapi.com/search/v3/prediction/feedback/d3e0c1f0-6859-4996-be7f-ef71485bb3e6/viewed/list/mqId:1234/mqId:4567/mqId:1122/mqId:8822
 */
@property(nullable, nonatomic, readwrite) NSString *resultClickedURL;

/**
 If there is direct interaction with a result (such as a click/tap), replace {/id} with the ID in the URL corresponding to the medium interacted with resultViewedURL and POST to the resulting URL
 
 Example: http://www.mapquestapi.com/search/v3/prediction/feedback/d3e0c1f0-6859-4996-be7f-ef71485bb3e6/clicked/map/mqId:1122
 */
@property(nullable, nonatomic, readwrite) NSString *resultViewedURL;

@end
