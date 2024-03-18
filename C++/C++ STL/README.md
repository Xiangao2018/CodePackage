## 六大部件

+ 容器（Containers）
+ 迭代器（Iterators）
+ 分配器（Allocators）
+ 算法（Algorithms）
+ 适配器(Adapters)
+ 仿函数（Functors）

Iterator 是一个泛化的指针，可以使用指针的对应操作

## range-based for statement

```c++
for( auto elem : vec ) {}

for( auto& elem : vec ) {}
```

## 容器（Containers）

+ 序列式容器（Sequence Containers）
+ 关联式容器（Associative Containers）

![](./imgs/Containers.png)

### 数组（Array）

### Vector

内存中，地址可以扩展，两倍扩展

+ size()
+ front()
+ back()
+ data()
+ capacity()

### list

双向链表

+ size()
+ max_size()
+ front()
+ back() 

标准库有一个 sort, 容器中也有个 sort

![](./imgs/list.png)
![](./imgs/list2.png)
![](./imgs/list3.png)
![](./imgs/list4.png)
![](./imgs/list5.png)
![](./imgs/Iterator.png)
![](./imgs/iterator2.png)
![](./imgs/traits.png)
![](./imgs/iterator_traits.png)

### forward_list 

单向链表
单项链表是插入在前面还是在后面?


### deque 
两边都可以扩充

![](./imgs/deque.png)

### Stack 

Containers adpator 

没有提供 Iterator

先进后出 

### queue

Containers adpator  

没有提供 Iterator

先进先出

### 关联式容器 multiset 

红黑树形成的结构

![](./imgs/multiset.png)

### 关联式容器 multimap

![](./imgs/multimap.png)

如何使用的操作

### 关联式容器 unordered_multiset

hashTable 结构

![](./imgs/unordered_multiset.png)

### set 
### map
### unordered_set 
### unordered_map


## 分配器 Allocator

![](./imgs/allocator.png)
![](./imgs/allocators.png)




 