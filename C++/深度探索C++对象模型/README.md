# 深度探索 C++ 对象模型读书笔记

## 第一章 关于对象

**名词:**
 + ADT: 抽象数据类型（abstract data type）


1. 每一个 non-inline member function 只会产生一个函数实体；
2. 每一个“拥有零个或一个定义”的 inline function 则会在其每一个使用者（模块）身上产生一个函数实体.


C++ 在布局以及存取时间上主要的额外负担是由 virtual 引起的，包括：

+ **virtual function 机制**用以支持一个有效率的 “执行期绑定”（runtime binding）
+  **virtual base class** 用以实现 “多次出现在继承体系中的 Base class, 有一个单衣而被共享的实体


### 1.1 C++ 对象模式（The C++ Object Model）

class data members(两种): static 和 nonstatic 
class member functions(三种)：static、nonstatic 和 virtual


+ nonstatic data member 被配置于每一个 class object 内；
+ static data member 被存放在所有的 class object 之外;

+ static 和 nonstatic function members 被放在所有的 class object 之外
+ **Virtual functions** 则以两个步骤支持:
	1. 每一个 class 产生一个虚表 virtual table（vtbl）, 虚表中保存指向 virtual function 的指针；
	2. 每一个 class object 被添加一个指针，指向虚表；
	   虚表的设定与重置由类的**构造函数**、**析构函数**和**copy assignment**运算符自动运行;
	   虚表第一个 slot 一般指向的是每一个关联的 type_info object(用以支持 runtime type identification, RTTI)

	![](./vtbl.png)



**多重继承与虚继承**







## 疑问：

### Q1: C++ 类中的虚函数有虚表指向，类对象有一个虚指针指向虚表，那么对于 static 和 nontatic function members，类或者类对象是如何调用的？ 

**非静态成员函数**
非静态成员函数与类的对象绑定，需要通过对象调用，或者通过对象指针/引用调用。它们依赖于类实例（对象）的 this 指针。具体调用过程如下：

**调用机制**：
1. 每个非静态成员函数隐式接收一个参数，即当前对象的地址（this 指针）。
2. 编译器会在调用非静态成员函数时，传递当前对象的地址给函数，以便函数可以访问对象的成员变量和其他非静态成员函数。


**对虚函数的调用**：
**虚函数表 (vtable)**：
1. 每个包含虚函数的类会有一张虚表，记录所有虚函数的地址。
2. 每个具体的对象实例会有一个指向虚表的指针，称为 虚指针 (vptr)。
3. 调用虚函数时，编译器通过 vptr 查找虚表中的函数地址，并调用相应的函数，实现动态绑定。

**静态成员函数**

静态成员函数不依赖于类的具体实例，因此：

1. 没有 this 指针。
2. 无法访问类的非静态成员变量或函数，除非通过对象实例显式传递。
3. 静态成员函数与类关联，而非具体对象。它们的调用完全是编译时静态绑定的。

**调用机制**
1. 静态成员函数的调用无需依赖对象，编译器直接根据函数名和类名查找对应的函数地址并调用。
2. 它与普通的全局函数类似，只是多了类名作用域限制。


### C++ 的虚继承怎么使用，以及有什么用


