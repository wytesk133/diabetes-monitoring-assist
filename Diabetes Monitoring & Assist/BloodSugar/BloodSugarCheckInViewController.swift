//
//  BloodSugarCheckInViewController.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 21/3/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import UIKit
import HealthKit

class BloodSugarCheckInViewController: UIViewController, UITextFieldDelegate {

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

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        bloodGlucose.resignFirstResponder()
        return true
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
