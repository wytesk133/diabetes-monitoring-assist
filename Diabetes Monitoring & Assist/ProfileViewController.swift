//
//  DashboardViewController.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 3/16/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import UIKit

class ProfileViewController: UIViewController ,UIPickerViewDelegate, UIPickerViewDataSource, UITextFieldDelegate{
    
    var CurrentTextField = UITextField()
    var pickerView = UIPickerView()
    
    
    
    
    
    
    
    var PoundRange:[String] = []
    var SexOption:[String] = []
    var TypeOption:[String] = []
    var FeetOption:[String] = ["0","1","2","3","4","5","6","7","8"]
    var InchOption:[String] = ["0","1","2","3","4","5","6","7","8","9","10","11"]
    
    
    @IBOutlet weak var TypeField: UITextField!
    @IBOutlet weak var WeightField: UITextField!
    @IBOutlet weak var HeightFields: UITextField!
    @IBOutlet weak var inputtextFIeld: UITextField!
    @IBOutlet weak var SexField: UITextField!
    private var datePicker: UIDatePicker?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        
        
        PoundRange = (65...350).map {String($0)}
        SexOption = ["Male","Female", "Other"]
        TypeOption = ["Pre-Diabetic", "Type 1 Diabetes", "Type 2 Diabetes" ]
        datePicker = UIDatePicker()
        datePicker?.datePickerMode = .date
        datePicker?.addTarget(self, action:#selector(ProfileViewController.dateChanged(datePicker:)), for: .valueChanged)
        
        let tapGesture  = UITapGestureRecognizer(target:self,action: #selector(ProfileViewController.viewTapped(gestureRecognizer:)))
        
        view.addGestureRecognizer(tapGesture)
        
        
        inputtextFIeld.inputView = datePicker
        //textFieldDidBeginEditing(CurrentTextField)
        //textFieldDidEndEditing(_, textField: UITextField)
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    @objc func viewTapped(gestureRecognizer: UITapGestureRecognizer)
    {
        view.endEditing(true)
    }
    @objc func dateChanged(datePicker: UIDatePicker)
    {
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "MM/dd/yyyy"
        
        inputtextFIeld.text = dateFormatter.string(from: datePicker.date)
        view.endEditing(true)
    }
    
    
    
    
    
    func textFieldDidBeginEditing(_ textField: UITextField) {
        self.pickerView.delegate = self
        self.pickerView.dataSource = self
        self.CurrentTextField.delegate = self
        CurrentTextField = textField
        
        if CurrentTextField == WeightField
        {
            CurrentTextField.inputView = pickerView
        }
        else if CurrentTextField == SexField
        {
            CurrentTextField.inputView = pickerView
        }
        else if CurrentTextField == HeightFields
        {
            CurrentTextField.inputView = pickerView
            
        }
        else if CurrentTextField == TypeField
        {
            CurrentTextField.inputView = pickerView
            
        }
        
        
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    
    func numberOfComponents(in pickerView: UIPickerView) -> Int {
        if CurrentTextField == HeightFields
        {return 2}
        return 1
        
    }
    
    func pickerView(_ pickerView: UIPickerView, numberOfRowsInComponent component: Int) -> Int {
        if CurrentTextField == WeightField
        {
            return PoundRange.count
            
        }
        else if CurrentTextField == SexField
        {
            return SexOption.count
        }
        else if CurrentTextField == HeightFields
        {
            if component == 0
            {return FeetOption.count}
            return InchOption.count
        }
        else if CurrentTextField == TypeField
        {
            return TypeOption.count
        }
        
        
        return 0
        
        
    }
    func pickerView(_ pickerView: UIPickerView, titleForRow row: Int, forComponent component: Int) -> String? {
        if CurrentTextField == WeightField
        {
            return PoundRange[row] + " lb"
            
        }
        else if CurrentTextField == SexField
        {
            return SexOption[row]
        }
        else if CurrentTextField == HeightFields
        {
            if component == 0
            {return FeetOption[row] + "' "}
            return InchOption[row] + "\" "
        }
        else if CurrentTextField == TypeField
        {
            return TypeOption[row]
        }
        return ""
    }
    
    func pickerView(_ pickerView: UIPickerView, didSelectRow row: Int, inComponent component: Int) {
        if CurrentTextField == WeightField
        {
            WeightField.text = PoundRange[row] + " lb"
            self.view.endEditing(true)
            
        }
        else if CurrentTextField == SexField
        {
            SexField.text = SexOption[row]
            self.view.endEditing(true)
        }
        else if CurrentTextField == HeightFields
        {
            var feet = FeetOption[pickerView.selectedRow(inComponent: 0)]
            var inches = InchOption[pickerView.selectedRow(inComponent: 1)]
            if component == 0
            {feet = FeetOption[row] + "\' "}
            else if component == 1
            {inches = InchOption[row] + "\" "}
            HeightFields.text = feet + " " + inches
            //self.view.endEditing(true)
        }
        else if CurrentTextField == TypeField
        {
            TypeField.text = TypeOption[row]
            self.view.endEditing(true)
        }
        
        
    }
    
}
