//
//  PlayView.swift
//  Landmarks
//
//  Created by Noah Gao on 2/24/25.
//

import SwiftUI

struct PlayButton: View {
    
    @Binding var isPlaying: Bool
    
    var body: some View {
        Button {
            withAnimation {
                self.isPlaying.toggle()
            }
        } label: {
            Label("SwiftUI", systemImage: isPlaying ? "pause.circle" : "play.circle")
        }
    }
}

struct PlayView: View {

    @State private var isPlaying = false
    
    var body: some View {
        
        VStack {
            PlayButton(isPlaying: $isPlaying)
            Spacer()
            
            Button {
                self.isPlaying.toggle()
            } label: {
                Image(systemName: isPlaying ? "pause.circle" : "play.circle")
            }
        }
        .background(isPlaying ? Color.green : Color.red)
    }
}

#Preview {
    PlayView()
}
