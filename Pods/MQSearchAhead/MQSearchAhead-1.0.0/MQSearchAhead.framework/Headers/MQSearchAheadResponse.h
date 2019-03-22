//
//  MQSearchAheadResponse.h
//  MapQuest
//
//  Copyright (c) 2018 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MQSearchAheadResult;
@class MQSearchAheadFeedback;

/**
 The response object that is returned from a search request.
 */
@interface MQSearchAheadResponse : NSObject

/**
 Feedback object returned when `includesFeedback` is set in the MQSearchAheadOptions class
 */
@property(nullable, nonatomic, readwrite) MQSearchAheadFeedback *feedback;
/**
 An array of search results
 */
@property(nullable, nonatomic, readwrite) NSArray<MQSearchAheadResult *> *results;

@end
