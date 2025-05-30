# Template Method 

## 动机

+ 在软件构建过程中，对于某一项任务额，它常常有**稳定**的整体操作步骤，但各个子步骤却又很多改变的需求，或者由于固有的原因（比如框架与应用之间的关系）而无法和任务的整体结构同时实现。
+ 如何下一个确定**稳定**操作结构的前提下，来灵活应对各个子步骤的变化或者晚期实现需求？ 

## 模式定义

定义一个操作中的算法的骨架（稳定），而将一些步骤延迟（变化）到子类中。Template Method 使得子类可以不改变（复用）一个算法的结构即可重定义（override 重写）该算法的某些特定步骤.

这个模式的前提是：有一个非常稳定的骨架，否则就不适合模板方法设计模式


## 要点总结

+ Template Method 模式是一种非常基础性的设计模式，在面向对象系统中有着大量的应用。它用最简洁的机制（虚函数的多态性）为很多应用程序框架提供了灵活的扩展点，是代码复用方面基本实现结构
+ 除了可以灵活应对子步骤的变化外，”不要调用我，让我来调用你“的反向控制结构是 Template Method 的典型应用
+ 在具体实现方面，被 Template Method 调用虚函数方法可以实现，也可以没有任何实现（抽象方法，纯虚方法），一般设置为 protected 方法。