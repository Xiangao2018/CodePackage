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
