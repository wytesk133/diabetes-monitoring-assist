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
}
