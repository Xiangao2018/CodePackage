# C++ 程序的生前死后-揭秘 CRT Startup code

> 源码之前，了无秘密

+ C++ 进入点是 main() 吗？
+ 什么代码比 main() 更早被执行？
+ 什么代码在 main() 结束后才被执行？
+ 为什么上述代码可以如此行为？ 
+ Heap 的结构如何？
+ I/O 的结构如何

## 目录

+ [X] 01 - 自定 Startup code 
+ [X] 02 - Startup code 在哪里



### 01-自定 Startup code

![](./imgs/自定%20Startup%20Code%2001.png)
![](./imgs/自定%20Startup%20Code%2002.png)
![](./imgs/自定%20Startup%20Code%2003.png)

### 02 - Startup code 在哪里

![](./imgs/Startup%20code%20在哪里%2001.png)
![](./imgs/Startup%20code%20在哪里%2002.png)

### 03- Startup code 源码摘要

![](./imgs/mainCRTStartup%2001.png)
![](./imgs/mainCRTStartup%2002.png)

### 04-heap init Startup的首要工程（上）

![](./imgs/heap%20init%2001.png)
![](./imgs/heap%20init%2002.png)
![](./imgs/heap%20init%2003.png)
![](./imgs/heap%20init%2004.png)

### 05 内存分配精解（一）

![](./imgs/内存分配%2001.png)
![](./imgs/内存分配%2002.png)
![](./imgs/内存分配%2003.png)
![](./imgs/内存分配%2004.png)

### 06 内存分配精解（二）

## 推荐书籍

+ 《程序员的自我修养-链接、装载与库》俞甲子/石凡/潘爱明 著
