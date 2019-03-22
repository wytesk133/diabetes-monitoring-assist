//
//  MQAnnotation.h
//  ios-core-model
//
//  Copyright (c) 2013 MapQuest. All rights reserved.
//

#if __has_feature(modules)
@import Foundation;
@import CoreLocation;
#else
#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#endif

@protocol MQAnnotation <NSObject>

@required

@property (nonatomic, readonly) CLLocationCoordinate2D coordinate;

@optional

@property (nonatomic, readonly, copy, nullable) NSString *title;
@property (nonatomic, readonly, copy, nullable) NSString *subtitle;

/**
 Serves as a way for annotations to indicate a preference
 for a reuse identifier. This can be useful when creating
 and configuring annotations outside of a MQMapViewClassic's 
 delegate.
 */
@property (nonatomic, copy, nullable) NSString *viewReuseIdentifier;

/** 
 Must be implemented if draggable is enabled
 @param coordinate the new location of the annotation 
 */
- (void)setCoordinate:(CLLocationCoordinate2D)coordinate;

/** Indicates whether the user or application could or should
    be able to navigate to the annotation.
 
    If this method is not implemented, the annotation will
    be treated as though it returned `YES`. Needing to provide
    an implementation is unusual. 
 */
- (BOOL)isNavigable;

@end
