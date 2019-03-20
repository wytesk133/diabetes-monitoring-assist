//
//  EnterInforViewController.m
//  Diabetes Monitoring & Assist
//
//  Created by Kunal Kathuria on 3/17/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

#import "EnterInforViewController.h"
#import "DBManager.h"
#import "BloodSugarView.h"
#import "ExerciseView.h"

@interface EnterInforViewController ()
@property (nonatomic, strong) DBManager *dbManager;
@property (nonatomic, strong) BloodSugarView *bloodSugar;
@property (nonatomic, strong) ExerciseView *exercise;
@end

@implementation EnterInforViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.dbManager = [[DBManager alloc] initWithDatabaseFilename:@"database.sql"];
    self.bloodSugar = [[BloodSugarView alloc] initWithNibName:@"BloodSugarView" bundle:nil];
    self.exercise = [[ExerciseView alloc] initWithNibName:@"ExerciseView" bundle:nil];
    NSDate *today = [NSDate date];
    NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
    [dateFormat setDateFormat:@"dd/MM/yyyy"];
    NSString *dateString = [dateFormat stringFromDate:today];
    NSLog(@"date: %@", dateString);
    self.Date = [dateFormat stringFromDate: today];
    self.CalorieIntake = [NSNumber numberWithFloat:2000];
    self.CarbohydrateIntake = [NSNumber numberWithFloat:100];
    
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
    NSLog(@" %f", [self.bloodSugar.bloodSugar.text floatValue]);
    self.BloodSugarLevel = [self.bloodSugar.bloodSugar.text floatValue];
    self.checkIn = self.bloodSugar.checkIn.text;
    self.ExerciseMinutes = [self.exercise.exerciseMin.text intValue];
    NSString *query = [NSString stringWithFormat:@"insert into checkininfo values(null, %f, '%@', %f, %f, %d, '%@')", self.BloodSugarLevel, self.Date, [self.CalorieIntake floatValue], [self.CarbohydrateIntake floatValue], self.ExerciseMinutes, self.checkIn];
    
    // Execute the query.
    [self.dbManager executeQuery:query];
    
    // If the query was successfully executed then pop the view controller.
    if (self.dbManager.affectedRows != 0) {
        NSLog(@"Query was executed successfully. Affected rows = %d", self.dbManager.affectedRows);
        
        // Inform the delegate that the editing was completed.
        [self.delegate editingInfoWasFinished];
        // Pop the view controller.
        [self.navigationController popToRootViewControllerAnimated:YES];
        NSLog(@"bloodSugarLevel: %f", self.BloodSugarLevel);
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
