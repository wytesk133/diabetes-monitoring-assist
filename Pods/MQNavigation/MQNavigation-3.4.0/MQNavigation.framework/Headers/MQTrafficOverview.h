//
//  MQTrafficOverview.h
//  MQNavigation
//
//  Copyright © 2018 MapQuest. All rights reserved.
//

/**
 Traffic Enumeration
 */
typedef NS_ENUM(NSInteger, MQTrafficOverview) {
    
    /// Light Traffic
    MQTrafficOverviewLight,
    /// Medium Traffic
    MQTrafficOverviewMedium,
    /// Heavy Traffic
    MQTrafficOverviewHeavy,
    /// No Traffic data available
    MQTrafficOverviewUnknown
};
