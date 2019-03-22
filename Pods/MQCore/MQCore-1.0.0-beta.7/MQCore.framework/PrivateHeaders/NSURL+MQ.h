//
//  NSURL+MQ.h
//  MQUtilities
//
//  Created by johnodwyer11 on 6/20/14.
//  Copyright (c) 2014 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif


@interface NSURL (MQ)

//Builds an NSURL based on the string parsed together with the values passed in
//The parameters passed in are translated to strings. Strings and NSNumbers are understood, all other objects use the description method
+ (NSURL *)urlWithBaseUrlString:(NSString *)baseUrl path:(NSString *)path parameters:(NSDictionary *)parameters;
@end
