//
//  MQApplicationKey.h
//  ios-core-model
//
//  Copyright © 2016 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif

@interface MQApplicationKey : NSObject

+ (NSString *)key;

@end
