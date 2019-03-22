//
//  MQPlace+Private.h
//  ios-core-model
//
//  Copyright (c) 2013 MapQuest. All rights reserved.
//

#import <MQCore/MQPlace.h>

@interface MQPlace(Private)

@property (nonatomic, copy) NSString *mqid;

- (NSDictionary*)toDictionaryUsingWinstonParams:(BOOL)useWinstonParamNames;
- (void)setMqid:(NSString *)mqid;

@end
