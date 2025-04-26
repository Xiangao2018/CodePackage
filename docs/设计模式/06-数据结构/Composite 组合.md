# Composite 组合

## 动机

![](./Composite%20组合%20动机.png)

## 模式定义

![](./Composite%20组合%20模式定义.png)

单个对象和组合对象有一致性，也就是组合对象与单个对象有一致的类型，遵循相同的接口

## 结构

![](./Composite%20组合%20结构.png)

这边有一点特殊的事 add 和 Remove 方法，Leaf 不应该添加，所以放在 Component 有点不合适（与截图不同，截图中是放在 Composite 中）

## 要点总结

![](./Composite%20组合%20要点总结.png)
