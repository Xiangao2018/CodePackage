# Adapter 适配器

## 动机

![](./Adapter%20动机.png)

![](./Adapter%20图解.png)

## 模式定义

![](./Adapter%20模式定义.png)

## 结构
![](./Adapter%20结构.png)

## 代码示例
```c++
// 目标接口（新接口）
class ITarget {
public:
    virtual void process() = 0;
};

// 遗留接口（老接口）
class IAdaptee {
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;
};

class OldClass: IAdaptee {
public:
    virtual void foo(int data) {}
    virtual int bar() {}
};

class Adapter: public ITarget {
protected:
    IAdaptee *pAdaptee;
public:
    Adapter(IAdaptee *pda): pAdaptee(pda);

    virtual void process() {
        int data = pAdaptee->bar();
        pAdaptee->foo(data);
    }
};

int main() {
    IAdaptee *pAdaptee = new OldClass();
    ITarget *pTarget = new Adapter(pAdaptee);

    pTarget->process();
}

```

## 要点总结

![](./Adapter%20要点总结.png)

采用多继承的方式，实现类适配器