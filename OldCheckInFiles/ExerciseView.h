//
//  ExerciseView.h
//  Diabetes Monitoring & Assist
//
//  Created by Kunal Kathuria on 3/19/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ExerciseView : UIViewController <UITextFieldDelegate>
@property (weak, nonatomic) IBOutlet UITextField *exerciseMin;
- (IBAction)saveExerciseMin:(id)sender;
@end

NS_ASSUME_NONNULL_END
