//
//  MQSearchAheadOptions+Internal.h
//  MQSearchAhead
//
//  Created by Alex Kac on 3/22/18.
//  Copyright © 2018 MapQuest. All rights reserved.
//

#import "MQSearchAheadOptions.h"

NS_ASSUME_NONNULL_BEGIN
@interface MQSearchAheadOptions()
@property (nonatomic, assign) BOOL mqUseB2CEndpoint;
- (NSDictionary*)parametersFromOptions;
@end

NS_ASSUME_NONNULL_END
