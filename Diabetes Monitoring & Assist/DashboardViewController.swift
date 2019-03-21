//
//  DashboardViewController.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 3/16/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import UIKit
import HealthKit

class DashboardViewController: UIViewController {

    @IBOutlet weak var scoreDay: UILabel!
    @IBOutlet weak var scoreWeek: UILabel!
    @IBOutlet weak var stepsDay: UILabel!
    @IBOutlet weak var stepsWeek: UILabel!
    @IBOutlet weak var caloriesDay: UILabel!
    @IBOutlet weak var caloriesWeek: UILabel!
    @IBOutlet weak var carbsDay: UILabel!
    @IBOutlet weak var carbsWeek: UILabel!
    @IBOutlet weak var bloodGlucoseDay: UILabel!
    @IBOutlet weak var bloodGlucoseWeek: UILabel!
    @IBOutlet weak var exerciseDistanceDay: UILabel!
    @IBOutlet weak var exerciseDistanceWeek: UILabel!

    func queryAndSetLabel(type: HKQuantityTypeIdentifier, unit: HKUnit, before: Date, divisor: Double? = nil, label: UILabel) {
        HealthKitConnector.query(type, before: before) { (samples, error) in
            guard let samples = samples else {
                if let error = error {
                    print(error)
                }
                return
            }
            var sum: Double = 0
            for entry in samples {
                sum += entry.quantity.doubleValue(for: unit)
            }
            var divisorValue: Double = 1
            if divisor == nil {
                divisorValue = Double(samples.count)
            }
            else {
                divisorValue = divisor!
            }
            sum /= divisorValue
            label.text = String(format: "%.0f", sum)
        }
    }

    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        // calculateScore()
        queryAndSetLabel(type: .stepCount, unit: .count(), before: .yesterday, divisor: 1, label: stepsDay)
        queryAndSetLabel(type: .stepCount, unit: .count(), before: .lastWeek, divisor: 7, label: stepsWeek)
        queryAndSetLabel(type: .dietaryEnergyConsumed, unit: .kilocalorie(), before: .yesterday, divisor: 1, label: caloriesDay)
        queryAndSetLabel(type: .dietaryEnergyConsumed, unit: .kilocalorie(), before: .lastWeek, divisor: 7, label: caloriesWeek)
        queryAndSetLabel(type: .dietaryCarbohydrates, unit: .gram(), before: .yesterday, divisor: 1, label: carbsDay)
        queryAndSetLabel(type: .dietaryCarbohydrates, unit: .gram(), before: .lastWeek, divisor: 7, label: carbsWeek)
        queryAndSetLabel(type: .bloodGlucose, unit: HKUnit(from: "mg/dL"), before: .yesterday, label: bloodGlucoseDay)
        queryAndSetLabel(type: .bloodGlucose, unit: HKUnit(from: "mg/dL"), before: .lastWeek, label: bloodGlucoseWeek)
        queryAndSetLabel(type: .distanceWalkingRunning, unit: .mile(), before: .yesterday, divisor: 1, label: exerciseDistanceDay)
        queryAndSetLabel(type: .distanceWalkingRunning, unit: .mile(), before: .lastWeek, divisor: 7, label: exerciseDistanceWeek)
    }

}
