//
//  CheckInController.h
//  Diabetes Monitoring & Assist
//
//  Created by Kunal Kathuria on 3/17/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "EnterInforViewController.h"


NS_ASSUME_NONNULL_BEGIN

@interface CheckInController : UIViewController <UITableViewDelegate, UITableViewDataSource, EnterInforViewControllerDelegate>
@property (weak, nonatomic) IBOutlet UITableView *checkInTable;

- (IBAction)newCheckIn:(id)sender;
@end

NS_ASSUME_NONNULL_END
