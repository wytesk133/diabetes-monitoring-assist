//
//  FoodCheckInViewController.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 3/18/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import UIKit

class FoodCheckInViewController: UIViewController, UITextFieldDelegate, UITableViewDataSource, UITableViewDelegate {

    @IBOutlet weak var searchBox: UITextField!
    @IBOutlet weak var foodTableView: UITableView!
    
    var foods = [Food]()
    
    @IBAction func changeListener(_ sender: UITextField) {
        let query = sender.text!
        if query == "" {
            return
        }
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
                if sender.text! == query {
                    self.foods = data
                    self.foodTableView.reloadData()
                }
            }
        }
    }

    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        searchBox.resignFirstResponder()
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
        cell.calories.text = String(format: "%.1f",item.calories)
        cell.thumbnail.image = item.thumbnail
        return cell
    }

    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        print("Recorded \(foods[indexPath.row].calories) calories")
        self.foodTableView.deselectRow(at: indexPath, animated: true)
        self.navigationController!.popViewController(animated: true)
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        self.foodTableView.keyboardDismissMode = .onDrag
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
