# Protocol Buffer 学习之基本概念

标签（空格分隔）： 未分类

---

最后更新: 2020.3.25
面向对象: Protobuf 小白用户

打开 [Protocol Buffer 官方](https://developers.google.com/protocol-buffers)（下面简称 “PB”）或者 Google 搜索 Protobuf 解释，一定能看到这几个词: 

+ 平台无关
+ 语言无关
+ 扩展好、兼容性高；
+ 序列化以及反序列化速度快

这几个词总结的很到位，但是对于小白来说，并不是那么好理解。我想用我最直白的话来解释下，PB 是 Google 内部定义的[接口描述语言](https://baike.baidu.com/item/IDL/34727)，





## Demo 遇到的问题
- [Why required and optional is removed in Protocol Buffers 3](https://stackoverflow.com/questions/31801257/why-required-and-optional-is-removed-in-protocol-buffers-3)  -- 其实就是为了兼容性处理， 后面需要考虑proto 是怎么保证兼容性的
