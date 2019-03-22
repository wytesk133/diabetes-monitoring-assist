//
//  MQShapeSegmenter.h
//  MQNavigation
//
//  Copyright © 2017 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MQShape;
@class MQSpanPathPair;
@class MQLocationCoordinate2DArray;
@class MQPositionSpan;

/**
 An object that provides sub-arrays from coordinates from a span
 */
@interface MQShapeSegmenter : NSObject

/**
 Creates a sub array from coordinates from span

 @param positionSpan Span that indicates start and end of the range
 @param shape MQShape object that represents shape of a route
 @return MQSpanPathPair object that has the span and subarray of
 */
+ (nullable MQSpanPathPair *)segmentIndividualSpan:(nonnull MQPositionSpan *)positionSpan inShape:(nonnull MQShape *)shape;


/**
 Creates a sub array from coordinates from span

 @param shape MQShape object that represents shape of a route
 @param spans Array of spans
 @return Array of span path pair objects
 */
+ (nullable NSArray <MQSpanPathPair *> *)segmentShape:(nonnull MQShape *)shape withSpans: (nonnull NSArray <MQPositionSpan *> *)spans;

@end
