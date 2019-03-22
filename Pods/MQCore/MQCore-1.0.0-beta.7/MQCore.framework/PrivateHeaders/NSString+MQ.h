//
//  NSString+MQ.h
//  Commute
//
//  Created by Fabian Canas on 1/7/14.
//  Copyright (c) 2013 MapQuest. All rights reserved.
//

@interface NSString (MQ)

+ (bool)isBlank:(NSString *)string;

- (NSString *)stripWhitespace;

/**
 * Make an ordinal string
 *
 * @param value input value to be turned into a string
 * @return ordinal string for value (0th, 1st, 2nd, 3rd, 4th, etc.)
 */
+ (NSString*) stringOrdinalFor:(NSUInteger)value;

+ (NSString*) urlQueryParameterEscaped:(NSString *)string DEPRECATED_MSG_ATTRIBUTE("use stringByAddingPercentEncodingWithAllowedCharacters instead");

//differs from urlQueryParameterEscaped by allowing certain characters in the key
+ (NSString*) urlQueryParameterKeyEscaped:(NSString *)string DEPRECATED_MSG_ATTRIBUTE("use stringByAddingPercentEncodingWithAllowedCharacters instead");

//appends the path along with a slash if its needed
+ (NSString *)stringWithBaseUrlString:(NSString *)baseUrl path:(NSString *)path;
@end
