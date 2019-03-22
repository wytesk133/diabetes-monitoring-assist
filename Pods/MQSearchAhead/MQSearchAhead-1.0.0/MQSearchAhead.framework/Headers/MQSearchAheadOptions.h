//
//  MQSearchAheadOptions.h
//  MapQuest
//
//  Copyright (c) 2018 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 An object that describes the search options such as search limit, language, and feedback
 */

@interface MQSearchAheadOptions : NSObject

/**
 An option whether to include feedback URLs in the results. https://developer.mapquest.com/documentation/searchahead-api/feedback/
 */
@property (nonatomic, assign) BOOL includesFeedback;

/**
 The number of items returned back from the search
 */
@property (nonatomic, assign) NSUInteger limit;

/**
 Language (locale) for search, nil defaults to en_US
 */
@property (nonatomic, copy, nullable) NSString *language;

@end

