# C++ 面向对象高级编程（下）

## 模板模板参数

```c++
template <typename T, template<typename U> class Container >

class XCLs 
{
private:
    Container<T> c;
public: 
    ....
}

```


```C++

template <typename T, class Sequence = deque<T>>
class stack {


protected:
    Sequece c; // 底层容器
}



```


## C++ 标准库

容器（container）
迭代器（Iterators）
算法（Algorithms）
仿函数（Functors）

## 数量不定的模板参数

```c++

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args )
{

}

```
sizeof...(args) 可以获取对应的不定参数的个数


## auto

## ranged-base for

```cpp
for (del : col) {}

for (int i : {1, 2, 3, 4}) {}

```
注意： pass by value 与 pass by reference


## reference

在堆上面指针： malloc 申请，需要free
在栈上面: int a = 10; int *p = &a;

引用的底层实际上也是使用指针来进行操作的

[](./imgs/Screenshot2024_01_21_223653.jpg)


reference 是一个漂亮的 point
 

## 构造与析构

继承由外到内构造，析构是由内到外

组合由内到位构造，由外到内析构

继承和组合关系下的构造与析构：

构造由内而外，析构是由外而内

## vptr 和 vtbl

![](./imgs/Screenshot%202024-01-23%20at%2021.58.15.png)

1. 只要类中有虚函数，类对象中会有一个 **虚表指针**
2. 继承继承的是调用权

(*(p->vptr)[n])(p);

**容器中不能存放大小不同的元素，所以继承关系中需要使用父类的指针**

动态绑定需要三个
1. 通过指针
2. 指针向上转型
3. 调用虚函数


## 谈谈 Const

1. const 放在成员函数后面表示通知编译器该方法不会改变成员变量
2. 成员函数后面的 const 算是签名的一部分
3. 当成员函数的 const 与 non-const 版本同时存在，const object 只能调用 const 版本，non-const object 只能调用 non-const 版本
