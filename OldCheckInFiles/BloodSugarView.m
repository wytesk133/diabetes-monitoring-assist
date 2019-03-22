//
//  BloodSugarView.m
//  Diabetes Monitoring & Assist
//
//  Created by Kunal Kathuria on 3/19/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

#import "BloodSugarView.h"


@interface BloodSugarView ()

@end

@implementation BloodSugarView

- (void)viewDidLoad {
    [super viewDidLoad];
    self.bloodSugar.delegate = self;
    self.checkIn.delegate = self;
    // Do any additional setup after loading the view.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

- (IBAction)saveBloodSugar:(id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}
@end
