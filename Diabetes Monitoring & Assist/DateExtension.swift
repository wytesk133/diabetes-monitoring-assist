//
//  DateExtension.swift
//  Diabetes Monitoring & Assist
//
//  Created by Kay Lab on 21/3/19.
//  Copyright © 2019 UC Irvine. All rights reserved.
//

import Foundation

// https://stackoverflow.com/a/44009988

extension Date {
    static var yesterday: Date {
        return Calendar.current.date(byAdding: .day, value: -1, to: Date())!
    }
    static var lastWeek: Date {
        return Calendar.current.date(byAdding: .day, value: -7, to: Date())!
    }
}
