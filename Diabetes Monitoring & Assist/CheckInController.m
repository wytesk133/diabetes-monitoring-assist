//
//  CheckInController.m
//  Diabetes Monitoring & Assist
//
//  Created by Kunal Kathuria on 3/17/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

#import "CheckInController.h"
#import "DBManager.h"

@interface CheckInController ()
@property (strong, nonatomic) DBManager *dbManager;
@property (strong, nonatomic) NSArray *arrCheckIns;

-(void) loadData;
@end

@implementation CheckInController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self loadData];
    self.checkInTable.delegate = self;
    self.checkInTable.dataSource = self;
    self.dbManager = [[DBManager alloc] initWithDatabaseFilename:@"database.sql"];
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

- (IBAction)newCheckIn:(id)sender {
    [self performSegueWithIdentifier:@"idSegueEditInfo" sender:self];
}

-(void)loadData{
    // Form the query.
    NSString *query = @"select * from checkininfo";
    // Get the results.
    if (self.arrCheckIns != nil) {
        self.arrCheckIns = nil;
    }
    self.arrCheckIns = [[NSArray alloc] initWithArray:[self.dbManager loadDataFromDB:query]];
    
    // Reload the table view.
    [self.checkInTable reloadData];
}

-(void)editingInfoWasFinished{
    [self loadData];
}

-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender{
    EnterInforViewController *enterInfoViewController = [segue destinationViewController];
    enterInfoViewController.delegate = self;
}

-(NSInteger)numberOfSectionsInTableView:(UITableView *)tableView{
    return 1;
}


-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{
    return self.arrCheckIns.count;
}


-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    return 60.0;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    // Dequeue the cell.
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"idCellRecord" forIndexPath:indexPath];
    
    NSInteger checkinIndex = [self.dbManager.arrColumnNames indexOfObject:@"bloodSugarLevel"];
    NSInteger dateIndex = [self.dbManager.arrColumnNames indexOfObject:@"date"];
    
    // Set the loaded data to the appropriate cell labels.
    cell.textLabel.text = [NSString stringWithFormat:@"%@", [[self.arrCheckIns objectAtIndex:indexPath.row] objectAtIndex:checkinIndex]];
    
    cell.detailTextLabel.text = [NSString stringWithFormat:@"Date: %@", [[self.arrCheckIns objectAtIndex:indexPath.row] objectAtIndex:dateIndex]];
    
    return cell;
}
@end
