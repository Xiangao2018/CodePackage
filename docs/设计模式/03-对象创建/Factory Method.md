# 工厂方法

## 动机

+ 在软件系统中，经常面临着创建对象的工作，由于需求的变化，需要常见的对象的具体类型经常变化；

```c++
class MainForm: public Form 
{
    TextBox* txtFilePath;
    TextBox* txtFileNumber;

    ProgressBar* progreeBar; // 使用 Bar 来看进度条

public:
    void Button1_Click() {
        string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());

        // 依赖抽象，不应该依赖细节
        FileSplitter splitter = new FileSplitter(filePath, number); // 传输到 FileSplitter 里面
        splitter.split();
    }
};

// 抽象基类
class ISplitter {
    virtual void split() = 0;
    virtual ~ISplitter() {}
}

class FileSplitter: ISplitter {};
class BinarySplitter: ISplitter{}
class TxtSplitter: {}
class PictureSplitter: ISplitter {}
class VideoSplitter: ISplitter{}

```

为了应对变化，采用抽象接口编程 `ISplitter`, 根据依赖倒置问题，应该依赖抽象，而不是依赖细节, 因此需要更改为抽象接口，但是在 New 方法的时候，依旧依赖了具体类型

```c++
class MainForm: public Form 
{
public:
    void Button1_Click() {
        // 依赖抽象，不应该依赖细节
        ISplitter splitter = new FileSplitter(filePath, number);  // 依旧依赖了具体类
        splitter.split();
    }
};

```

```c++

class SplitterFactory {
public: 
    ISplitter* CreateSplitter(...) { 
        return new FileSplitter(filePath, number) 
    }
}

class MainForm: public Form 
{
public:
    void Button1_Click() {

        SplitterFactory factory;

        ISplitter splitter = factory.CreateSplitter();  // 依旧依赖了具体类
        splitter.split();
    }
};

```
以后还是产生了依赖关系， MainFrom 依赖于 SplitterFactory,  SplitterFactory 依赖于 New FileSplitter

在 C++ 中，虚函数是运行时依赖

```C++

class SplitterFactory {
public: 
    virtual Splitter* CreateSplitter() = 0;
    virtual ~SplitterFactory() {} 
}

class MainForm: public Form 
{
public:
    void Button1_Click() {

        SplitterFactory *factory; // ? 

        ISplitter splitter = factory->CreateSplitter();  // 依旧依赖了具体类
        splitter.split();
    }
};

// 具体类
class FileSplitter: ISplitter {};
class BinarySplitter: ISplitter{}
class TxtSplitter: {}
class PictureSplitter: ISplitter {}
class VideoSplitter: ISplitter{}

// 具体类工厂
class BinarySplitterFactory: SplitterFactory { 
    virtual Splitter* CreateSplitter() override {
        return new BinarySplitter()
    };
}
...
class VideoSplitterFactory: SplitterFactory { 
    virtual Splitter* CreateSplitter() override {
        return new VideoSplitter()
    };
};

``

如何指定对应的工厂，这就成为了另一个问题,由外部进行创建

```C++

class MainForm: public Form 
{
    SplitterFactory *factory;
public:
    MainForm(SplitterFactory *f): factory(f) {}

    void Button1_Click() {
        ISplitter splitter = factory->CreateSplitter();  // 依旧依赖了具体类
        splitter.split();
    }
};

```
这样改变之后，MainForm 没有产生具体的依赖对象，在在外面依旧会产生对象。并不是把依赖对象具体地方消灭掉了，而是把具体对象放到另外一个地方去。

这里其实还有个问题，不使用 Factory，直接使用 ISplitter 呢? 


## 模式定义

定义一个用于创建对象的接口，让子类决定实例化哪一个类。 Factory Method 使得一个类的实例化延迟（目的： 解耦，手：虚函数）到子类


## 结构

![](./factory%20megthod%20Structure.png)


## 要点总结

+ Factory  Method 模式用于隔离对象的使用者和具体类型之间的耦合关系，面对一个经常变化的具体类型，紧耦合关系（New）会导致软甲脆弱

+ Factory Method 模式将通过面向对象的手法，将索要创建的具体对象工作延迟到子类，从而实现一种扩展（而非更改）的策略，较好的解决耦合的关系

+ Factory Method 模式解决 “单个对象”的需求变化。缺点在于要求创建方法/参数相同


## 其他问题

该设计模式未考虑对象的释放问题




