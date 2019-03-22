//
//  NSDate+MQ.h
//  mq_ios_sdk
//
//  Created by JohnO'Dwyer on 8/24/12.
//  Copyright (c) 2012 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif

@interface NSDate (MQ)

//Usually, the value passed in will look like this: 1345789822000
//in this case, the dividedBy value should be 1000
//in the case no division needs to be done, the dividedBy value should be nil
+ (NSDate *) dateFromIntervalSince1970FromString:(NSString *)intervalString dividedBy:(NSNumber *)dividedBy;

//Returns values like "Just now", "5 min ago", "2 hours ago". Anything after "now", returns nil
+ (NSString *) informalIntervalSinceDate:(NSDate *)pastDate;

+ (NSDate *)dateWithISO8601String:(NSString *)dateString;

//Returns a date string in the format "1/31/2013"
+ (NSString *)monthDayYear:(NSDate *)date;
@end
