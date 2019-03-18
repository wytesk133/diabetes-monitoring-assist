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
@property (weak, nonatomic) IBOutlet UITextField *BloodSugarLevel;
@property (weak, nonatomic) IBOutlet UITextField *Date;
@property (weak, nonatomic) IBOutlet UITextField *CalorieIntake;
@property (weak, nonatomic) IBOutlet UITextField *CarbohydrateIntake;
@property (weak, nonatomic) IBOutlet UITextField *checkIn;
@property (weak, nonatomic) IBOutlet UITextField *ExerciseMinutes;
- (IBAction)saveCheckIn:(id)sender;
@property (strong, nonatomic) id<EnterInforViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
