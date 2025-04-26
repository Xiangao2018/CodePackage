# 原型模式 

## 动机

+ 在软件系统中，经常面临着“某些结构复杂的对象”的创建工作；由于需求的变化，这些对象面临着剧烈的变化，但却有稳定的接口
+ 如何应对这种变化？ 如何向“客户程序（使用这些对象的程序）”隔离处“这些易变的对象”，从而使得“依赖这些易变对象的客户程序”不对着需求改变而改变


```c++

class ISplitter {
public:
    virtual void split() = 0;
    virtual ISplitter *clone() = 0; // 通过克隆自己来创建对象

    virtual ~ISplitter() {} 
};

class BinarySplitter: public ISplitter {
public:
    virtual ISplitter *clone() {
        return new BinarySplitter(*this);
    }
};

class TxtSplitter: public ISplitter {
public:
    virtual ISplitter *clone() {
        return new TxtSplitter(*this);
    }
};

class MainForm: public Form 
{
    ISplitter *m_splitter;

    MainForm(ISplitter *splitter) : m_splitter(splitter) {}

public:
    void Button1_Click() {
        
        ISplitter splitter = m_splitter->Clone();
        splitter.split();
    }
};

```

## 模式定义

使用原型实例指定创建对象的种类，。然后通过拷贝这些原型来创建新的对象。

## 结构

![](./prototype%20structure.png)

## 要点总结

+ Prototype 模式同样用于隔离类对象的使用者和具体类型（易变类）之间的耦合关系，它同样要求这些“易变类”拥有“稳定的接口”；
+ Prototype 模式对于“如何创建易变类的实体对象”采用“原型克隆”的方法来做，它使得我们可以非常灵活地动态创建“拥有某些稳定接口”的新对象-所需工作仅仅是注册一个新类的对象（即原型），然后在任何需要的地方 Clone
+ Prototype 模式中的 Clone 方法可以利用某些框架中的序列化来实现深拷贝