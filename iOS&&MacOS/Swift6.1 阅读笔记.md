# Swift 6.1 阅读笔记

好久没写 Swift 了，上次还是在 Swift 1.x ~ 4.x 的时候，Swift 5 之后基本上没有写过，很多都忘记了，这次阅读 Swift 6.1 基础语法文档，记录下来一些模糊不清的地方，或许是以前没留意，或者是后来新加的功能。

[Swift 6.1 文档链接](https://doc.swiftgg.team/documentation/the-swift-programming-language/)

## 1. 常量声明可以在稍后进行分配数值

![](./imgs/Swift%206.1/Swift%206.1-01.png)

## 2. Swift 支持多行注释的嵌套

![](./imgs/Swift%206.1/Swift%206.1-02.png)

## 3. 整数边界

![](./imgs/Swift%206.1/Swift%206.1-03.png)


## 4.十进制与十六进制的字面值常量

![](./imgs/Swift%206.1/Swift%206.1-04.png)

```swift 
let hexadecimalDouble = 0xC.3p0 
  C   .3             p 0
(12 + 3 * (1/16)） * 2^0 = 12.1875

```

## 5. 可选值解包的命名规范

![](./imgs/Swift%206.1/Swift%206.1-05.png)

## 6. if 中的并列判断 

![](./imgs/Swift%206.1/Swift%206.1-06.png)

## 7. 余数运算法的计算规则

1. a % b 与 a % -b 答案是一致的
2. 规则：某个乘数是 b 在 a 中能容纳的最大倍数

![](./imgs/Swift%206.1/Swift%206.1-07.png)


## 8. 元组比较规则

从第一个元素开始进行比较

![](./imgs/Swift%206.1/Swift%206.1-08.png)
