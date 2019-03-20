//
//  EnterInforViewController.h
//  Diabetes Monitoring & Assist
//
//  Created by Kunal Kathuria on 3/17/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol EnterInforViewControllerDelegate

-(void)editingInfoWasFinished;

@end

@interface EnterInforViewController : UIViewController <UITextFieldDelegate>
@property (nonatomic) float BloodSugarLevel;
@property (nonatomic) NSString *Date;
@property (nonatomic) NSNumber *CalorieIntake;
@property (nonatomic) NSNumber *CarbohydrateIntake;
@property (weak, nonatomic) NSString *checkIn;
@property (nonatomic) int ExerciseMinutes;
- (IBAction)saveCheckIn:(id)sender;
@property (strong, nonatomic) id<EnterInforViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
