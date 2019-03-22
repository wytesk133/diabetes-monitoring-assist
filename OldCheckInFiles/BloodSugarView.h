//
//  BloodSugarView.h
//  Diabetes Monitoring & Assist
//
//  Created by Kunal Kathuria on 3/19/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface BloodSugarView : UIViewController <UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UITextField *bloodSugar;
@property (weak, nonatomic) IBOutlet UITextField *checkIn;
- (IBAction)saveBloodSugar:(id)sender;

@end

NS_ASSUME_NONNULL_END
