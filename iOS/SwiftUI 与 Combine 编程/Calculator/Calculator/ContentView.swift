//
//  ContentView.swift
//  Calculator
//
//  Created by Noah Gao on 9/11/25.
//

import SwiftUI

enum CalculatorButtonItem {
    enum Op: String {
        case plus = "+"
        case minus = "-"
        case divide = "÷"
        case multiply = "×"
        case equal = "="
    }
    
    enum Command: String {
        case clear = "AC"
        case flip = "+/-"
        case percent = "%"
    }
    
    case digit(Int)
    case dot
    case op(Op)
    case command(Command)
}

extension CalculatorButtonItem: Hashable {}

extension CalculatorButtonItem {
    var title: String {
        switch self {
        case .digit(let value): return String(value)
        case .dot: return "."
        case .op(let op): return op.rawValue
        case .command(let command): return command.rawValue
        }
    }
    
    var size: CGSize {
        return CGSize(width: 88, height: 88)
    }
    
    var backgroundColorName: String {
        switch self {
        case .digit, .dot: return "digitBackground"
        case .op: return "operatorBackground"
        case .command: return "commandBackground"
        }
    }
}

struct CalculatorButton: View {
    let fontSize: CGFloat = 38
    let title: String
    let size: CGSize
    let backgroudColorName: String
    let action: () -> Void
    
    var body: some View {
        Button {
            action()
        } label: {
            Text(title)
                .font(.system(size: fontSize))
                .foregroundStyle(.white)
                .frame(width: size.width, height: size.height)
                .background(Color(backgroudColorName))
                .cornerRadius(size.width / 2)
        }
    }
}

struct ContentView: View {
    
    let row: [CalculatorButtonItem] = [
        .digit(1), .digit(2), .digit(3), .op(.plus),
    ]
    
    var body: some View {
        HStack {
            ForEach(row, id: \.self) { item in
                CalculatorButton(title: item.title, size: item.size, backgroudColorName: item.backgroundColorName) {
                    print("Button: \(item.title)")
                }
            }
        }
    }
}

#Preview {
    ContentView()
}
