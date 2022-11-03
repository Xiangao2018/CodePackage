# 《C++ Primer 第五版》 练习 9.32 详解

标签（空格分隔）： 未分类

---
Apple clang version 14.0.0 (clang-1400.0.29.102)
Target: x86_64-apple-darwin21.6.0
Thread model: posix

## 问题

在第 316 页的程序中，向下面语句这样调用 insert 是否合法？ 如果不合法，为什么？ 

```c++
iter = vi.insert(iter, *iter++);
```

第 316 页的程序如下：

```c++
vector<int> vi = {1, 2, 3, 4, 5, 6, 7, 8};

auto iter = vi.begin();

while( iter != vi.end() )
{
	if( *iter % 2 )
	{			
		iter = vi.insert(iter, *iter++);	
		iter += 2;
	}
	else
	{
		iter = vi.erase(iter);
	}		
}

```
我在 [Stackoverflow](https://stackoverflow.com/questions/17574944/post-incrementing-an-iterator-after-de-referencing-iter-how-is-it-evaluate) 搜到类似的问题，但是与我的理解有点不一致，因此记录下来。

## 分析

这里使用的是迭代器来遍历 vector, 删除偶数元素，复制奇数元素。当我们使用 `iter = vi.insert(iter, *iter++); `时候，其中有 `insert` 会返回插入元素的迭代器。`*iter++` 会先取出迭代器的值随后将迭代器 + 1;

在上面的示例中，`vi` 进行初始化后，`count` 和 `capacity` 相等，当插入后













