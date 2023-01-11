# g++ 与 gcc 区别

一直都不是很清楚 g++ 与 gcc 具体区别，一直简单的理解为: `g++ 是编译 C++ 文件, gcc 是编译 C 文件`，用着也没啥问题。看到 stackoverflow 有一个关于 [What is the difference between g++ and gcc?](https://stackoverflow.com/questions/172587/what-is-the-difference-between-g-and-gcc)，因此总结记录下。


**GCC**: GNU Compiler Collection，翻译过来就是 GNU 编译器合集，它支持 Fortran、Pascal、Objective-C、Java、Ada，Go 等语言。

**gcc**: 是 GCC 中的 C 编译器（GUN C Compile）；

**g++**: 是 GCC 中的 C++ 编译器（GUN C++ Compiler）；

**主要区别：**

1. `gcc` 编译 C 和 C++ 文件时，区分 C 文件和 C++ 文件；
   
2. `g++` 编译 C 和 C++ 文件时，全部当做 C++ 文件处理；
   
3. **g++ 编译文件时，会自动链接 C++ 标准库， 而 gcc 不会**；
   
4. `gcc` 编译 C 文件时预定义宏比较少
   
5. `gcc` 编译 C++ 文件时，有一些额外的宏处理；
    ```c++
    #define __GXX_WEAK__ 1
    #define __cplusplus 1
    #define __DEPRECATED 1
    #define __GNUG__ 4
    #define __EXCEPTIONS 1
    #define __private_extern__ extern
    ```

从上述区别来说，推荐用法：C++ 文件用 g++， C 文件用 gcc

## 讨论：
上面提到: **g++ 编译文件时，会自动链接 C++ 标准库， 而 gcc 不会；**

一种说法是 `g++` 差不多相等于 `gcc -xc++ -lstdc++ -shared-libgcc`，使用 gcc 编译 C++ 文件，的确能编译成功，但是实际上还有更多区别，在[这里评论区](https://stackoverflow.com/a/173007/9572831) 可以看到。

