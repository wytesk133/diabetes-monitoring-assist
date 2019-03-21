//
//  BloodSugarListViewController.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 21/3/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import UIKit
import HealthKit

class BloodSugarListViewController: UIViewController, UITableViewDataSource {

    @IBOutlet weak var bloodSugarTableView: UITableView!

    var entries = [HKQuantitySample]()

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return entries.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = tableView.dequeueReusableCell(withIdentifier: "BloodSugarCell", for: indexPath) as? BloodSugarTableRow else {
            fatalError("The dequeued cell is not an instance of BloodSugarCell.")
        }
        
        let sample = entries[indexPath.row]
        let unit = "mg/dL"
        let value = String(sample.quantity.doubleValue(for: HKUnit(from: unit)))
        cell.bloodGlucose.text = "\(value) \(unit)"
        let dateFormatter = DateFormatter()
        dateFormatter.dateStyle = DateFormatter.Style.medium
        dateFormatter.timeStyle = DateFormatter.Style.medium
        cell.date.text = dateFormatter.string(from: sample.startDate)
        cell.selectionStyle = .none
        return cell
    }

    override func viewWillAppear (_ animated: Bool) {
        super.viewWillAppear(animated)
        HealthKitConnector.query(.bloodGlucose) { (samples, error) in
            guard let samples = samples else {
                if let error = error {
                    print(error)
                }
                return
            }
            self.entries = samples
            self.bloodSugarTableView.reloadData()
        }
    }

}
