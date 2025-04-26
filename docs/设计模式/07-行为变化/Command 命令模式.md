# Command 命令模式

## 动机

![](./Command%20命令模式%20动机.png)

## 模式定义

![](./Command%20命令模式%20模式定义.png)

```c++

class Command {
public:
    virtual void execute() = 0;
};

class ConcreteCommand1: public Command {

};

class ConcreteCommand2: public Command {

};

class MacroCommand: public Command { // 此处是 Composite 设计模式

};

```

## 结构

![](./Command%20命令模式%20结构.png)


## 要点总结

![](./Command%20命令模式%20要点总结.png)

在 C++ 中，函数对象的使用是优于 Command 设计模式,但在其他设计模式中，是存在这个设计模式的