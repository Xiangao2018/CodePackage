//
//  LandmarksApp.swift
//  Landmarks
//
//  Created by Noah Gao on 2/20/25.
//

import SwiftUI

//@main
//struct LandmarksApp: App {
//    var body: some Scene {
//        WindowGroup {
//            ContentView()
//            ContentView()
//        }
//    }
//}


@main
struct LandmarksApp: App {
    @State private var modelData = ModelData()
    
    var body: some Scene {
        WindowGroup {
            PlayView()
//            ContentView()
                .environment(modelData)            
        }
    }
}
