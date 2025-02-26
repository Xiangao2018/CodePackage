//
//  BookView.swift
//  Landmarks
//
//  Created by Noah Gao on 2/24/25.
//

import SwiftUI

@Observable
class Book {
    var title = "A simple book"
    var isAvailable = true
}


struct BookContentView: View {
    
    @State private var book = Book()
    
    var body: some View {
        VStack{
            BookView(book: book)
            Button {
                book.isAvailable.toggle()
                book.title = book.isAvailable ? "A simple Book" : "Unavailable"
            } label: {
                Image(systemName: book.isAvailable ? "pause.circle" : "play.circle")
            }
        }
    }
}

struct BookView: View {
    var book: Book
    var body: some View {
        Text( book.title)
    }
}

#Preview {
    BookContentView()
}
