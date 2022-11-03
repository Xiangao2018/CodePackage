# FFmpeg学习之视频播放器制作（一）-前言以及准备工作

标签（空格分隔）： FFmpeg

---



## 一、前言

这个系列文章主要是参考[雷神的教程](https://blog.csdn.net/leixiaohua1020/article/details/47068015)以及网上其他相关资料。虽然网上资料不少，但是由于以下原因，我还是打算记录下来

+ 检测自己学习情况；
+ Mac 平台独特性
+ 网上资料层次不齐，很多资料代码都过时甚至不能运行。

大多时候，在阅读他人博客、视频以及相关代码时，很容易给自己造成我看完了我就会了的错觉，然而在实际工程实践中，同样的代码在不同的环境下可能出现的结果会不一样。碰到问题，解决问题才能真正的提升自己的能力。记录自己曾经碰过的雷，踩过的坑也避免以后耗时耗力再去解决相同的问题。

网上音视频相关的教程大多数是运行在 Windows 或者 Linux 系统上，在 Mac 上运行的资料很少。仅有的资料中很多都是到处复制粘贴的，很多甚至都不能运行起来。接下来的系列教程中的代码，100% 保证是在当前笔者 Mac 系统上运行的。如果由于代码库更新而无法运行，麻烦在[这里](https://github.com/AVPackage/Blog)或者在留言区给我反馈下，我会第一时间更新相关内容，感激不尽。

## 二、准备工作

### 2.1 软件安装
1. [Homebrew](https://brew.sh/) 是 MacOS 系统上非常优秀的软件包管理系统，在 MacOS 安装包以及对应软件大多都可以通过它来完成. 官方安装链接在[这里](https://brew.sh/)。

2. Xcode 从 AppStore 下载即可。

3. [pkg-config](https://zh.m.wikipedia.org/zh-hans/Pkg-config) 是一款在编译期间查询安装库的一个软件, pkg-config 主要提供如下功能：

    > + 检查库的版本号。 如果所需要的库的版本不满足要求，它会打印出错误信息，避免链接错误版本的库文件
    > + 获得编译预处理参数，如宏定义、头文件的位置
    > + 获得链接参数，如库及依赖的其他库的位置，文件名及其他一些链接参数
    > + 自动加入所依赖的其他库的设置
    
    > 引自: https://ivanzz1001.github.io/records/post/linux/2017/09/08/linux-pkg-config

    你可以再终端敲 `pkg-config --version` 来查看电脑中的版本，如果未安装，可以使用 `brew install pkg-config` 来进行安装

4. [FFmpeg](https://www.ffmpeg.org/) 是我们的主角，可以执行音频和视频封装、编解码、转换等功能，是学习音视频必学内容之一。你可以通过 brew 进行安装，但是建议下载源码到本地进行安装，FFmpeg 项目中包含一系列的 example 以及源码，值得我们去学习。
    
    [FFmpeg](https://www.ffmpeg.org/) 安装十分简单，你可以通过 [Github](https://github.com/FFmpeg/FFmpeg)下载源码, 然后根据 [INSTALL.md](https://github.com/FFmpeg/FFmpeg/blob/master/INSTALL.md) 安装即可。

5. [SDL](https://www.libsdl.org/) 是一套多媒体开发库，目前使用的是 sdl2，使用 `brew install sdl2` 安装即可。其他工具程序使用这种方式安装即可

### 2.2 项目准备

按照按照如下构建对应的目录结构，

```
.
├── CMakeLists.txt
├── lib
│   ├── FFmpeg
│   │   └── CMakeLists.txt
│   └── SDL
│       └── CMakeLists.txt
└── src
    └── main.cpp
    
```
![](https://raw.githubusercontent.com/AganCoder/Imgs/main/imgs/20220616234258.png)

---

在最外层的 CMakeLists.txt 将下列代码复制进去

```
cmake_minimum_required(VERSION 3.22.0)

project(Demo VERSION 0.1.0 LANGUAGES CXX C)

add_subdirectory(lib/FFmpeg)
add_subdirectory(lib/SDL2)

add_definitions(-DGL_SILENCE_DEPRECATION)
list(APPEND SOURCES src/main.cpp)

add_executable(Demo ${SOURCES})

target_link_libraries(Demo FFmpeg SDL2)

```
[cmake_minimum_required](https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html) 表示需要的 cmake 的最低版本，当前笔者电脑最新版本是 3.23.2, 因此采用最新的版本；
[project](https://cmake.org/cmake/help/latest/command/project.html) 项目名称，必须全局唯一
[add_subdirectory](https://www.jianshu.com/p/07acea4e86a3) 添加一个子目录，并构建子目录，子目录里面需要有 CMakeLists.txt 文件.
[add_definitions](https://cmake.org/cmake/help/latest/command/add_definitions.html) 增加编译的宏
[list](https://cmake.org/cmake/help/latest/command/list.html) 向 SOURCES 添加 main.cpp 文件
[add_executable](https://cmake.org/cmake/help/latest/command/add_executable.html) 生成一个可执行的目标文件。
[target_link_libraries](https://cmake.org/cmake/help/latest/command/target_link_libraries.html) 为目标链接相应的资源库。


---

在 lib/FFmpeg/CmakeLists.txt 文件添加下面代码

```
cmake_minimum_required(VERSION 3.13.0)
project(FFmpeg)

find_package(PkgConfig REQUIRED)
pkg_check_modules(AVCODEC REQUIRED IMPORTED_TARGET libavcodec)
pkg_check_modules(AVFORMAT REQUIRED IMPORTED_TARGET libavformat)
pkg_check_modules(AVFILTER REQUIRED IMPORTED_TARGET libavfilter)
pkg_check_modules(AVDEVICE REQUIRED IMPORTED_TARGET libavdevice)
pkg_check_modules(AVUTIL REQUIRED IMPORTED_TARGET libavutil)
pkg_check_modules(SWRESAMPLE REQUIRED IMPORTED_TARGET libswresample)
pkg_check_modules(SWSCALE REQUIRED IMPORTED_TARGET libswscale)


add_library(FFmpeg INTERFACE IMPORTED GLOBAL)

target_link_libraries(FFmpeg INTERFACE
	PkgConfig::AVCODEC
	PkgConfig::AVFORMAT
	PkgConfig::AVFILTER
	PkgConfig::AVDEVICE
	PkgConfig::AVUTIL
	PkgConfig::SWRESAMPLE
	PkgConfig::SWSCALE
)

```
我们采用 PkgConfig 来进行管理，pkg_check_modules 检查各种 FFmpeg 各种模块，并生成以 PkgConfig:: 开头的库的名称. add_library 用来生成 FFmpeg 库，target_link_libraries 将 FFmpeg 全部链接起来

> 注意：project(FFmpeg) 是我们自己生成的一个 library, 不要与 FFmpeg 工具混淆
> 此处的 FFmpeg library 目的是用来管理 libavcodec、libavformat 仓库而已

--- 

在 lib/SDL2/CMakeLists.txt 添加如下代码

```
cmake_minimum_required(VERSION 3.22.0)
project(SDL2)

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED IMPORTED_TARGET sdl2)

add_library(SDL2 INTERFACE IMPORTED GLOBAL)

target_link_libraries(SDL2 INTERFACE PkgConfig::SDL2)
```

---

此时已经将一些准备工作做完了。

### 测试项目

在 main.cpp 中添加如下代码进行测试

```
#include <iostream>

extern "C" {
    #include<libavformat/avformat.h>
    #include<libavutil/avutil.h>
    #include<libavcodec/avcodec.h>
}

using namespace std;

int main(int argc, char const *argv[])
{
    // url 文件换成你想要查看的视频文件
    const char *url = "xxxxx";
    AVFormatContext *avformatContext = NULL;
    int ret = avformat_open_input(&avformatContext, url, NULL, NULL);
    if( ret != 0 )
    {
        cout << av_err2str(ret) << endl;
        return -1;
    }
    
    cout << "Hello world" << endl;
        
    return 0;
}

```