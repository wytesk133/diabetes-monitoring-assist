//
//  BloodSugarCheckInViewController.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 21/3/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import UIKit
import HealthKit

class BloodSugarCheckInViewController: UIViewController {

    @IBOutlet weak var bloodGlucose: UITextField!
    @IBOutlet weak var datePicker: UIDatePicker!

    @IBAction func saveData(_ sender: Any) {
        HealthKitConnector.save(dataType: .bloodGlucose, unit: HKUnit(from: "mg/dL"), value: Double(bloodGlucose.text!)!, date: datePicker.date) { (success, error) in
            if success {
                DispatchQueue.main.async {
                    self.navigationController?.popViewController(animated: true)
                }
            }
            else {
                print(error!)
            }
        }
    }

}
