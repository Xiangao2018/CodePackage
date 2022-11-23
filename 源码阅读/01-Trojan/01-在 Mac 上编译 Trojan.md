# 01-在 Mac 上源代码编译安装 Trojan.md

官方在[这里](https://github.com/trojan-gfw/trojan/blob/master/docs/build.md)提供了如何编译 Trojan 的教程，笔者没有找到 Mac 平台上编译过程，自己编了一下，碰了些问题，记录下来。

在编译安装之前，你需要电脑已经安装了对应的库文件，mac 上最简单的方式可以通过 homebrew 安装

- [CMake](https://cmake.org/) >= 3.7.2 
- [Boost](http://www.boost.org/) >= 1.66.0
- [OpenSSL](https://www.openssl.org/) >= 1.1.0
- [libmysqlclient](https://dev.mysql.com/downloads/connector/c/)

```
brew install cmake
brew install boost
brew install openssl
brew install mysql
```


## Clone

```shell
git clone https://github.com/trojan-gfw/trojan.git
cd trojan/
```

## Build and Install

```
mkdir build
cd build/
cmake ..
make
ctest
sudo make install

```
当在进行 `cmake ..` 时候，你可能会遇到如下问题：

```shell
CMake Error at /usr/local/Cellar/cmake/3.23.2/share/cmake/Modules/FindPackageHandleStandardArgs.cmake:230 (message):
  Could NOT find OpenSSL, try to set the path to OpenSSL root folder in the
  system variable OPENSSL_ROOT_DIR (missing: OPENSSL_CRYPTO_LIBRARY
  OPENSSL_INCLUDE_DIR) (Required is at least version "1.1.0")
Call Stack (most recent call first):
  /usr/local/Cellar/cmake/3.23.2/share/cmake/Modules/FindPackageHandleStandardArgs.cmake:594 (_FPHSA_FAILURE_MESSAGE)
  /usr/local/Cellar/cmake/3.23.2/share/cmake/Modules/FindOpenSSL.cmake:578 (find_package_handle_standard_args)
  CMakeLists.txt:31 (find_package)

```
其中表示 `OPENSSL_INCLUDE_DIR` 无法找打，因此在执行 cmake 的时候，可以使用 `-D`指定 openssl 的目录

```shell
cmake -DOPENSSL_ROOT_DIR=/usr/local/opt/openssl ../
```

> brew install 安装软件一般都会放在 /usr/local/Cellar/，openssl 也放在里面，你也可以指定 /usr/local/Cellar/ 里面的目录