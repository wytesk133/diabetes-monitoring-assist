//
//  Food.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 3/18/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import UIKit

struct Food {
    let foodName: String
    let brandName: String
    let quantity: Double
    let quantityUnit: String
    let calories: Double
    let thumbnail: UIImage?
    
    init?(fromJson json: [String: Any]) {
        guard let foodName = json["food_name"] as? String,
            let brandName = json["brand_name"] as? String,
            let quantity = json["serving_qty"] as? Double,
            let quantityUnit = json["serving_unit"] as? String,
            let calories = json["nf_calories"] as? Double
            else {
                return nil
        }
        self.foodName = foodName
        self.brandName = brandName
        self.quantity = quantity
        self.quantityUnit = quantityUnit
        self.calories = calories
        if let photo = json["photo"] as? [String: Any],
            let thumbnailUrlString = photo["thumb"] as? String,
            let thumbnailUrl = URL(string: thumbnailUrlString),
            let thumbnailData = try? Data(contentsOf: thumbnailUrl) {
            self.thumbnail = UIImage(data: thumbnailData)
        }
        else {
            self.thumbnail = nil
        }
    }
}
