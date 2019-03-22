//
//  MQTrackingIdentity.h
//  Pods
//
//  Created by JohnO'Dwyer on 2/20/14.
//
//

#if __has_feature(modules)
@import Foundation;
#else
#import <Foundation/Foundation.h>
#endif

typedef NS_ENUM(NSInteger, MQDeviceIDType) {
    MQDeviceIDTypeAd,
    MQDeviceIDTypeVendor,
    MQDeviceIDTypeUnknown
};

@interface MQTrackingIdentity : NSObject

/**
 determines if the advertiser id should be used or not for identifying the device
 */
+ (void)setUseAdvertiserID:(BOOL)useAdvertiserID;
+ (BOOL)useAdvertiserID;

//returns the best possible unique id for the phone
+ (NSString *)uniqueDeviceID;

+ (MQDeviceIDType)deviceIdType;

//returns the string name associated with the MQDeviceIDType in deviceIDType
+ (NSString *)deviceIdTypeName;

//returns the bundle id but included here since it is called in multiple places
+ (NSString *)applicationID;

//returns the version id but included here since it is called in multiple places
+ (NSString *)applicationVersion;

+ (NSString *)deviceName;

//returns the os version with the pre fix i so that it can be distiguished with android of the back-end
+ (NSString *)osVersion;

+ (NSString *)vendorId;

+ (NSString *)adId;
@end
