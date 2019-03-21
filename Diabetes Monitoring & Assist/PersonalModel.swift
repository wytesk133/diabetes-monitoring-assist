//
//  PersonalModel.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 21/3/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import Foundation

enum Gender {
    case female
    case male
    case other
}

class PersonalModel {

    static var age: Int = 21
    static var gender: Gender = .male
    static var height: Double = 1.80
    static var weight: Double = 70

    class func getIntegerAgeInYear()->Int {
        return PersonalModel.age
    }
    class func setIntegerAgeInYear(_ age: Int) {
        PersonalModel.age = age
    }

    class func getGender()->Gender {
        return PersonalModel.gender
    }
    class func getGender(_ gender: Gender) {
        PersonalModel.gender = gender
    }

    class func getDoubleHeightInMeter()->Double {
        return PersonalModel.height
    }
    class func setDoubleHeightInMeter(_ height: Double) {
        PersonalModel.height = height
    }

    class func getDoubleWeightInKilogram()->Double {
        return PersonalModel.weight
    }
    class func setDoubleWeightInKilogram(_ weight: Double) {
        PersonalModel.weight = weight
    }

    class func getBMI()->Double {
        return PersonalModel.weight/(PersonalModel.height*PersonalModel.height)
    }

}

