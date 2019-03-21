//
//  FoodApi.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 3/18/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import Foundation

let nutritionixAppId = "..."
let nutritionixAppKey = "..."
let searchApiEndpoint = "https://trackapi.nutritionix.com/v2/search/instant"
let itemApiEndpoint = "https://trackapi.nutritionix.com/v2/search/item"
let energyKcal = 208
let carbohydratesGram = 205

class FoodApi {

    class func search(_ query: String, completionHandler: @escaping ([Food]?, String?) -> Void) {
        guard var urlComponents = URLComponents(string: searchApiEndpoint) else {
            completionHandler(nil, "Invalid URL")
            return
        }
        urlComponents.queryItems = [
            URLQueryItem(name: "query", value: query)
        ]
        guard let url = urlComponents.url else {
            completionHandler(nil, "Failed building URL")
            return
        }
        
        var urlRequest = URLRequest(url: url)
        urlRequest.setValue(nutritionixAppId, forHTTPHeaderField: "x-app-id")
        urlRequest.setValue(nutritionixAppKey, forHTTPHeaderField: "x-app-key")
        
        let urlSession = URLSession(configuration: .ephemeral)
        
        let task = urlSession.dataTask(with: urlRequest) { (data, response, error) in
            guard error == nil else {
                completionHandler(nil, "Request failed")
                // print(error!)
                return
            }
            
            guard let response = response as? HTTPURLResponse else {
                completionHandler(nil, "Invalid response")
                return
            }
            guard response.statusCode == 200 else {
                completionHandler(nil, "HTTP status code \(response.statusCode)")
                return
            }
            
            guard let data = data else {
                completionHandler(nil, "No data received")
                return
            }
            
            guard let json = (try? JSONSerialization.jsonObject(with: data)) as? [String: Any] else {
                completionHandler(nil, "JSON serialization failed")
                return
            }
            
            guard let brandedFoods = json["branded"] as? [[String: Any]] else {
                completionHandler(nil, "Cannot access branded food")
                return
            }
            
            var result = [Food]()
            for foodJson in brandedFoods {
                if let foodObj = Food(fromJson: foodJson) {
                    result.append(foodObj)
                }
            }
            completionHandler(result, nil)
        }
        task.resume()
    }

    class func queryCarbs(id: String, completionHandler: @escaping ([String: Double?]?, String?) -> Void) {
        guard var urlComponents = URLComponents(string: itemApiEndpoint) else {
            completionHandler(nil, "Invalid URL")
            return
        }
        urlComponents.queryItems = [
            URLQueryItem(name: "nix_item_id", value: id)
        ]
        guard let url = urlComponents.url else {
            completionHandler(nil, "Failed building URL")
            return
        }
        
        var urlRequest = URLRequest(url: url)
        urlRequest.setValue(nutritionixAppId, forHTTPHeaderField: "x-app-id")
        urlRequest.setValue(nutritionixAppKey, forHTTPHeaderField: "x-app-key")
        
        let urlSession = URLSession(configuration: .ephemeral)
        
        let task = urlSession.dataTask(with: urlRequest) { (data, response, error) in
            guard error == nil else {
                completionHandler(nil, "Request failed")
                // print(error!)
                return
            }
            
            guard let response = response as? HTTPURLResponse else {
                completionHandler(nil, "Invalid response")
                return
            }
            guard response.statusCode == 200 else {
                completionHandler(nil, "HTTP status code \(response.statusCode)")
                return
            }
            
            guard let data = data else {
                completionHandler(nil, "No data received")
                return
            }
            
            guard let json = (try? JSONSerialization.jsonObject(with: data)) as? [String: Any] else {
                completionHandler(nil, "JSON serialization failed")
                return
            }
            
            guard let foods = json["foods"] as? [[String: Any]],
                let firstFood = foods.first,
                let nutritions = firstFood["full_nutrients"] as? [[String: Any]] else {
                completionHandler(nil, "Cannot access nutrition data")
                return
            }
            
            var result: [String: Double?] = ["energyKcal": nil, "carbohydratesGram": nil]
            for nutrition in nutritions {
                if let attribute = nutrition["attr_id"] as? Int,
                   let value = nutrition["value"] as? Double {
                    if attribute == energyKcal {
                        result["energyKcal"] = value
                    }
                    if attribute == carbohydratesGram {
                        result["carbohydratesGram"] = value
                    }
                }
            }
            completionHandler(result, nil)
        }
        task.resume()
    }

}
