# 桥模式 Bridge

## 动机

+ 由于某些类型的固有的视线逻辑，使得它们具有多个变化维度

## 模式定义

+ 将抽象部分与实现部分分离，使他们可以独立的变化


```c++
class Messager {
public: 
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;
};

class PCMessagerBase: public Messager {
public: 
    virtual void PlaySound() {}
    virtual void DrawShape() {}
    virtual void WriteText() {}
    virtual void Connect() {}
};

class MobileMessagerBase: public Messager {
public: 
    virtual void PlaySound() {}
    virtual void DrawShape() {}
    virtual void WriteText() {}
    virtual void Connect() {}
};

// 业务抽象

class PCMessagerLite: public PCMessagerBase {
public: 
    virtual void Login(string username, string password) {
        PCMessagerBase::Connect();
    }
    virtual void SendMessage(string message) {
        PCMessagerBase::WriteText();
    }
    virtual void SendPicture(Image image) {
        PCMessagerBase::DrawShape();
    }
}

class PCMessagerPrefect: public PCMessagerBase {
public: 
    virtual void Login(string username, string password) {
        PCMessagerBase::PlaySound();
        PCMessagerBase::Connect();
    }
    virtual void SendMessage(string message) {
        PCMessagerBase::PlaySound();
        PCMessagerBase::WriteText();
    }
    virtual void SendPicture(Image image) {
        PCMessagerBase::PlaySound();
        PCMessagerBase::DrawShape();
    }
}

class MobileMessagerLite: public MobileMessagerBase {
public: 
    virtual void Login(string username, string password) {
        MobileMessagerBase::Connect();
    }
    virtual void SendMessage(string message) {
        MobileMessagerBase::WriteText();
    }
    virtual void SendPicture(Image image) {
        MobileMessagerBase::DrawShape();
    }
}

class MobileMessagerPrefect: public MobileMessagerBase {
public: 
    virtual void Login(string username, string password) {
        MobileMessagerBase::PlaySound();
        MobileMessagerBase::Connect();
    }
    virtual void SendMessage(string message) {
        MobileMessagerBase::PlaySound();
        MobileMessagerBase::WriteText();
    }
    virtual void SendPicture(Image image) {
        MobileMessagerBase::PlaySound();
        MobileMessagerBase::DrawShape();
    }
}

```

这种情况下，如果平台为 N， 子类的对象为 N * M, 类对象的复杂为 1 + n + m * n; 而且平台之间会存在大量的重复代码

可以通过继承转组合来完成对应的内容；

```c++

class MessagerLite {
    Messager *messager;
public: 
    virtual void Login(string username, string password) {
        messager->Connect();
    }
    virtual void SendMessage(string message) {
        messager->WriteText();
    }
    virtual void SendPicture(Image image) {
        messager->DrawShape();
    }
}

class MessagerPrefect {
    Messager *messager;
public: 
    virtual void Login(string username, string password) {
        messager->PlaySound();
        messager->Connect();
    }
    virtual void SendMessage(string message) {
        messager->PlaySound();
        messager->WriteText();
    }
    virtual void SendPicture(Image image) {
        messager->PlaySound();
        messager->DrawShape();
    }
}

```
这种做法能消除大部分的平台不一致内容，但是 `MessagerPrefect`


## 结构 

![](./bridge%20structure.png)


## 要点总结

+ Bridge 模式使用“对象间的组合关系”解耦了抽象和实现之间固有的绑定关系，使得抽象和实现可以沿着各自的维度来变化。所谓抽象和实现沿着各自维度的变化，即 “子类化”它们
+ Bridge 模式有时候类似于多继承方案，但是多继承方案往往违背单一职责原则，复用性交叉。
+ Bridge 模式的应用一般在"两个非常强的变化维度"，有时一个类也有多余两个变化维度，这时可以使用 Bridge 的扩展模式