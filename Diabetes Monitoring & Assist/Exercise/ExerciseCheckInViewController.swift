//
//  ExerciseCheckInViewController.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 21/3/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import UIKit
import HealthKit

class ExerciseCheckInViewController: UIViewController, UITextFieldDelegate {

    @IBOutlet weak var distance: UITextField!
    @IBOutlet weak var datePicker: UIDatePicker!

    @IBAction func saveData(_ sender: Any) {
        HealthKitConnector.save(dataType: .distanceWalkingRunning, unit: HKUnit.mile(), value: Double(distance.text!)!, date: datePicker.date) { (success, error) in
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

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        textField.resignFirstResponder()
        return true
    }

}
