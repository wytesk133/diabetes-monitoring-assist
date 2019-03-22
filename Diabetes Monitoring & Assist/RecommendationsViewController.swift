//
//  RecommendationsViewController.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 3/16/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import UIKit
import UserNotifications

class RecommendationsViewController: UIViewController {

    @IBAction func night(_ sender: Any) {
        let content2 = UNMutableNotificationContent()
        content2.title = "Night Notification"
        content2.subtitle = "It is time!"
        content2.body = "Based on your current statistics you should workout more and eat carbs with less calories. Also get enough sleep!"
        content2.badge = 1
        
        let trigger2 = UNTimeIntervalNotificationTrigger(timeInterval: 5, repeats: false)
        let request2 = UNNotificationRequest(identifier: "timerDone", content: content2, trigger: trigger2)
        
        UNUserNotificationCenter.current().add(request2, withCompletionHandler: nil)
    }
    @IBAction func action(_ sender: Any) {
        let content = UNMutableNotificationContent()
        content.title = "Morning Notification"
        content.subtitle = "It is time!"
        content.body = "Good Morning please make sure to check your glucose levels and take your medication."
        content.badge = 1
        
        let trigger = UNTimeIntervalNotificationTrigger(timeInterval: 5, repeats: false)
        let request = UNNotificationRequest(identifier: "timerDone", content: content, trigger: trigger)
        
        UNUserNotificationCenter.current().add(request, withCompletionHandler: nil)
        
       
        
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        
        UNUserNotificationCenter.current().requestAuthorization(options: [.alert,.sound,.badge], completionHandler: {didAllow, error in})
        
        // Do any additional setup after loading the view.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
