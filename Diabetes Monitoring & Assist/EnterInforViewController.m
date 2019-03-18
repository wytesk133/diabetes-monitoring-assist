//
//  EnterInforViewController.m
//  Diabetes Monitoring & Assist
//
//  Created by Kunal Kathuria on 3/17/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

#import "EnterInforViewController.h"
#import "DBManager.h"

@interface EnterInforViewController ()
@property (nonatomic, strong) DBManager *dbManager;
@end

@implementation EnterInforViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dbManager = [[DBManager alloc] initWithDatabaseFilename:@"database.sql"];
    self.BloodSugarLevel.delegate = self;
    self.Date.delegate = self;
    self.CalorieIntake.delegate = self;
    self.CarbohydrateIntake.delegate = self;
    self.ExerciseMinutes.delegate = self;
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

- (IBAction)saveCheckIn:(id)sender {
    NSString *query = [NSString stringWithFormat:@"insert into checkininfo values(null, %f, '%@', %f, %f, %d, '%@')", [self.BloodSugarLevel.text floatValue], self.Date.text, [self.CalorieIntake.text floatValue], [self.CarbohydrateIntake.text floatValue], [self.ExerciseMinutes.text intValue], self.checkIn.text];
    
    // Execute the query.
    [self.dbManager executeQuery:query];
    
    // If the query was successfully executed then pop the view controller.
    if (self.dbManager.affectedRows != 0) {
        NSLog(@"Query was executed successfully. Affected rows = %d", self.dbManager.affectedRows);
        
        // Inform the delegate that the editing was completed.
        [self.delegate editingInfoWasFinished];
        // Pop the view controller.
        [self.navigationController popViewControllerAnimated:YES];
    }
    else{
        NSLog(@"Could not execute the query.");
    }
}
-(BOOL)textFieldShouldReturn:(UITextField *)textField{
    [textField resignFirstResponder];
    return YES;
}
@end
