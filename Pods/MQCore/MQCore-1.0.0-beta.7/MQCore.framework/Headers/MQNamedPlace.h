//
//  MQNamedPlace.h
//  ios-core-model
//
//  Copyright (c) 2013 MapQuest. All rights reserved.
//

#import <MQCore/MQPlace.h>

/** Just like a MQPlace but it also has a name */
@interface MQNamedPlace : MQPlace

@property (nonatomic, copy) NSString *name;

@end
