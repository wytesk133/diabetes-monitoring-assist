//
//  DBManager.h
//  Diabetes Monitoring & Assist
//
//  Created by Kunal Kathuria on 3/17/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DBManager : NSObject
@property (nonatomic, strong) NSMutableArray *arrColumnNames;
@property (nonatomic) int affectedRows;
@property (nonatomic) long long lastInsertedRowID;

-(instancetype)initWithDatabaseFilename:(NSString *)dbFilename;
-(NSArray *)loadDataFromDB:(NSString *)query;
-(void)executeQuery:(NSString *)query;
@end

NS_ASSUME_NONNULL_END
