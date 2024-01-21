#include <iostream>

#ifdef ANDROID
#define SYSTEM "Android"
#else 
#define SYSTEM "Apple"
#endif

// 这里是注释
// 预处理的时候:g++ -E 2.1-HelloWorld.cpp -o 2.1-HelloWorld.i
// 1. 展开宏定义(#define)；
// 2. 处理与编译指令（#if、 #ifdef #elif、#else、#endif）；
// 3. 删除所有的注释
// 4. 添加文件行号与文件表示
// 5. 保留 #pragma 编译器指令
// 
// 编译: g++ -S 2.1-HelloWorld.i -o 2.1-HelloWorld.s 或者 g++ -S 2.1-HelloWorld.cpp -o 2.1-HelloWorld.s
// 词法分析、语法分析、语义分析以及优化生成对应的汇编代码文件
// 
// 汇编: as 2.1-HelloWorld.s  -o 2.1-HelloWorld.o 或者 g++ -c 2.1-HelloWorld.s -o 2.1-HelloWorld1.o
// 将汇编代码转换成机器可以执行的指令, 每一个源文件(.cpp) 或者编译后的文件(.s) 生成对应的目标文件
// 
// 链接: 使用链接器(ld)目标文件链接起来，生成可执行的文件
// 

int main(int argc, char **argv)
{
    std::cout << "Hello world! " << SYSTEM << std::endl;

    return 0;
}