//
//  FoodCheckInViewController.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 3/18/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import UIKit
import HealthKit

class FoodCheckInViewController: UIViewController, UITextFieldDelegate, UITableViewDataSource, UITableViewDelegate {

    @IBOutlet weak var foodTableView: UITableView!
    
    var foods = [Food]()

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        let query = textField.text!
        FoodApi.search(query) { (data, error) in
            guard error == nil else {
                print("Error: \(error!)")
                return
            }
            guard let data = data else {
                print("Error: no data")
                return
            }
            DispatchQueue.main.async {
                self.foods = data
                self.foodTableView.reloadData()
            }
        }
        textField.resignFirstResponder()
        return true
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return foods.count
    }

    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        guard let cell = tableView.dequeueReusableCell(withIdentifier: "FoodCell", for: indexPath) as? FoodTableRow else {
            fatalError("The dequeued cell is not an instance of FoodCell.")
        }

        let item = foods[indexPath.row]
        cell.foodName.text = item.foodName
        cell.foodDescription.text = "\(item.brandName), \(item.quantity) \(item.quantityUnit)"
        cell.calories.text = String(format: "%.1f", item.calories)
        cell.thumbnail.image = item.thumbnail
        return cell
    }

    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        FoodApi.queryCarbs(id: foods[indexPath.row].id) { (data, error) in
            guard error == nil else {
                print("Error: \(error!)")
                return
            }
            if let calories = data?["energyKcal"] {
                HealthKitConnector.save(dataType: .dietaryEnergyConsumed, unit: .kilocalorie(), value: calories!, date: Date()) { (success, error) in
                    if success {
                        print("Recorded \(calories!) kcal")
                    }
                    else {
                        print(error!)
                    }
                }
            }
            if let carbohydrates = data?["carbohydratesGram"] {
                HealthKitConnector.save(dataType: .dietaryCarbohydrates, unit: .gram(), value: carbohydrates!, date: Date()) { (success, error) in
                    if success {
                        print("Recorded \(carbohydrates!) grams")
                    }
                    else {
                        print(error!)
                    }
                }
            }
            DispatchQueue.main.async {
                self.foodTableView.deselectRow(at: indexPath, animated: true)
                self.navigationController!.popViewController(animated: true)
            }
        }
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.foodTableView.keyboardDismissMode = .onDrag
    }

}
