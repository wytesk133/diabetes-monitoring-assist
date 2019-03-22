//
//  MQTrafficFlowAnnotation.h
//
//  Copyright (c) 2016 MapQuest. All rights reserved.
//

#import <Mapbox/MGLPolyline.h>


/**
 This class represents traffic flow annotations on the map
 */
@interface MQTrafficFlowAnnotation : MGLPolyline

///style string that represents traffic severity of the flow annotation
@property (nonatomic, strong) NSString *style;

@end
