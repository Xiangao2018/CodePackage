# C++ 面向对象高级编程（上）

目标：
+ 包含指针的类对象设计：例如 String
+ 不包含指针的类对象设计：例如 Complex

Object Based: 面对的是单一 class 的设计
Object Oriented：面对的是多重 classes 的设计， classes 与 classes 之间的关系

## 构造函数
对象被创建，一定会调用构造函数
函数的重载

构造对象函数放在 Private 里面

```c++
class A {
public: 
    static A& getInstance();
    
private: 
    A();
    A(const A& );
}

```

## const 

函数后面添加 const: 表示不会改变数据


## 相同 class 的各个 objects 互为 friends(友元)

##  return by referemce or value

一个函数的操作结果：
C1 += C2 
Local 变量不能使用 reference 

## 操作符重载

所有的成员函数都包含一个隐含的参数 **this**

### 操作符重载之一：成员函数

C2 += C1;

传递者无需知道接收者是以 reference 形式接收

### 操作符重载之一：非成员函数

临时对象

C2 = C1 + C2
C2 = C1 + 5
C2 = 5 + C1

-C1
-C2

C1 == C2
C1 == 2 
2 == C1

cout <<  这种操作符只能当做非成员函数写法

## 包含指针的类对象设计

拷贝构造与拷贝赋值，这个操作编译器会默认生成一套

如果行为跟默认的不相同，就需要自定义一套


**只要类中包含了指针，就需要自定义拷贝构造与拷贝赋值**


S2= S1 这个造成的操作

## 堆、栈与内存管理

new: 先分配内存，然后调用构造函数
delete： 先调用析构函数，然后调用 delete

动态分配内存的时候，调试情况下，系统会有很多的数据结构


41 最后的 1 表示已经被使用

16 

## static

static data members
static member functions

static 有单独的存储空间，只有一份


## 组合与继承

## 虚函数与多态

