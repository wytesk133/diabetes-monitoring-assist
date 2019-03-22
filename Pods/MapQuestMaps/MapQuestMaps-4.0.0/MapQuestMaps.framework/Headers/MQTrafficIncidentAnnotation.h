//
//  MQTrafficIncident.h
//
//  Copyright (c) 2013 MapQuest. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <Mapbox/MGLAnnotation.h>

/**
Traffic incident type
*/
typedef NS_ENUM(NSInteger, MQTrafficIncidentType) {
    ///unknown type
    MQTrafficIncidentTypeUnknown,
    
    ///traffic incident type
    MQTrafficIncidentTypeIncident,

    ///construction type
    MQTrafficIncidentTypeConstruction
};


/**
 This class represents traffic incident annotations
 */
@interface MQTrafficIncidentAnnotation : NSObject<MGLAnnotation>

///id string of the incident
@property(nonatomic, copy) NSString *idString;

/**
 Incident type. Values are:
 1. Construction
 2. Event
 3. Congestion/Flow
 4. Incident/accident
 */
@property(nonatomic) NSInteger type;

///The incident severity. Values range from 0-4 with 4 indicating the highest severity.
@property(nonatomic) NSInteger severity;

///The incident event code. These are standard Alert-C event codes.
@property(nonatomic) NSInteger eventCode;

///Latitude of the incident.
@property(nonatomic, copy) NSNumber *lat;

///Longitude of the incident.
@property(nonatomic, copy) NSNumber *lng;

///The start time (ISO 8601 Combined Date and Time format) of the incident.
@property(nonatomic, copy) NSString *startTime;

///The end time (ISO 8601 Combined Date and Time format) of the incident.
@property(nonatomic, copy) NSString *endTime;

///A short description of the incident.
@property(nonatomic, copy) NSString *shortDesc;

///A full description of the incident.
@property(nonatomic, copy) NSString *fullDescription;

///URL for an icon to use for displaying the incident
@property(nonatomic, copy) NSString *iconURL;

///Incident type
@property(nonatomic, readonly) MQTrafficIncidentType incidentType;

@end
