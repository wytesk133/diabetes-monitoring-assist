/**
 * Copyright (c) 2017 Razeware LLC
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Notwithstanding the foregoing, you may not use, copy, modify, merge, publish,
 * distribute, sublicense, create a derivative work, and/or sell copies of the
 * Software in any work that is designed, intended, or marketed for pedagogical or
 * instructional purposes related to programming, coding, application development,
 * or information technology.  Permission for such use, copying, modification,
 * merger, publication, distribution, sublicensing, creation of derivative works,
 * or sale is expressly withheld.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

import HealthKit

class HealthKitConnector {

    private enum HealthkitSetupError: Error {
        case notAvailableOnDevice
        case dataTypeNotAvailable
    }

    class func authorizeHealthKit(completionHandler: @escaping (Bool, Error?) -> Void) {
        //1. Check to see if HealthKit Is Available on this device
        guard HKHealthStore.isHealthDataAvailable() else {
            completionHandler(false, HealthkitSetupError.notAvailableOnDevice)
            return
        }
        //2. Prepare the data types that will interact with HealthKit
        guard let bloodSugar = HKObjectType.quantityType(forIdentifier: .bloodGlucose),
            let calories = HKObjectType.quantityType(forIdentifier: .dietaryEnergyConsumed),
            let carbohydrates = HKObjectType.quantityType(forIdentifier: .dietaryCarbohydrates),
            let stepCount = HKObjectType.quantityType(forIdentifier: .stepCount),
            let exerciseDistance = HKObjectType.quantityType(forIdentifier: .distanceWalkingRunning) else {
                completionHandler(false, HealthkitSetupError.dataTypeNotAvailable)
                return
        }
        //3. Prepare a list of types you want HealthKit to read and write
        let healthKitTypesToWrite: Set<HKSampleType> = [bloodSugar, calories, carbohydrates, exerciseDistance]
        let healthKitTypesToRead: Set<HKObjectType> = [bloodSugar, calories, carbohydrates, stepCount, exerciseDistance]
        //4. Request Authorization
        HKHealthStore().requestAuthorization(toShare: healthKitTypesToWrite,
                                             read: healthKitTypesToRead) { (success, error) in
                                                completionHandler(success, error)
        }
    }

    class func query(_ dataType: HKQuantityTypeIdentifier, before startDate: Date = .distantPast, completionHandler: @escaping ([HKQuantitySample]?, Error?) -> Void) {
        //1. Use HKQuery to load the most recent samples.
        guard let sampleType = HKObjectType.quantityType(forIdentifier: dataType) else {
            completionHandler(nil, HealthkitSetupError.dataTypeNotAvailable)
            return
        }
        let mostRecentPredicate = HKQuery.predicateForSamples(withStart: startDate,
                                                              end: Date(),
                                                              options: .strictEndDate)
        let sortDescriptor = NSSortDescriptor(key: HKSampleSortIdentifierStartDate,
                                              ascending: false)
        let limit = 1000000
        let sampleQuery = HKSampleQuery(sampleType: sampleType,
                                        predicate: mostRecentPredicate,
                                        limit: limit,
                                        sortDescriptors: [sortDescriptor]) { (query, samples, error) in
                                            //2. Always dispatch to the main thread when complete.
                                            DispatchQueue.main.async {
                                                guard let samples = samples else {
                                                    completionHandler(nil, error)
                                                    return
                                                }
                                                completionHandler(samples as? [HKQuantitySample], nil)
                                            }
        }
        HKHealthStore().execute(sampleQuery)
    }

    class func save(dataType: HKQuantityTypeIdentifier, unit: HKUnit, value: Double, date: Date, completionHandler: @escaping (Bool, Error?) -> Void) {
        //1.  Make sure the type exists
        guard let dataTypeObj = HKQuantityType.quantityType(forIdentifier: dataType) else {
            completionHandler(false, HealthkitSetupError.dataTypeNotAvailable)
            return
        }
        //2.  Use the HKUnit to create a quantity object
        let quantity = HKQuantity(unit: unit, doubleValue: value)
        let sample = HKQuantitySample(type: dataTypeObj,
                                      quantity: quantity,
                                      start: date,
                                      end: date)
        //3.  Save the sample to HealthKit
        HKHealthStore().save(sample) { (success, error) in
            if let error = error {
                print("Error Saving Sample: \(error.localizedDescription)")
                completionHandler(false, error)
            } else {
                print("Successfully saved Sample")
                completionHandler(true, nil)
            }
        }
    }
}
