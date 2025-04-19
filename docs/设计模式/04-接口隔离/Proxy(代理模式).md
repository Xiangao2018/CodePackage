# Proxy 代理模式

## 动机

![](./Proxy%20动机.png)


## 模式定义

![](./Proxy%20模式定义.png)

## 结构

![](./Proxy%20结构.png)

## 示例

```c++
class ISubject {
public:
    virtual void process();
};

class RealSubject: public ISubject {
public:
    virtual void process() {        
    }
};

class ClientApp {
    ISubject *subject;
public:
    ClientApp() {
        subject = new ReakSubject();
    }

    void DoTask() {
        subject->process();
    }
};

```

如果某种原因无法直接拿到 RealSubject，就会存在一些问题

```c++
class ISubject {
public:
    virtual void process();
};

class SubjectProxy: public ISubject {
public:
    virtual void process() {   
        // 对 RealSubject 的一种间接访问     
    }
};

class ClientApp {
    ISubject *subject;
public:
    ClientApp() {
        subject = new SubjectProxy();
    }

    void DoTask() {
        subject->process();
    }
};

```

## 要点总结

![](./Proxy%20要点总结.png)