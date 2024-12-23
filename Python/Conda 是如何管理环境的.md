# Conda 是如何管理环境的

## 前言

一直使用 Python 的包管理工具 pip 来管理 Python 包，但随着项目越来越复杂，依赖的包越来越多，pip 的不足之处也越来越明显。尤其是在版本管理方面，pip 的版本管理功能非常弱，无法满足复杂项目的需求。因此使用 Conda 来管理 Python 包和依赖项。

以前没有深究 Conda 的原理，只是知道 Conda 可以管理 Python 包和依赖项，可以创建和管理不同的 Python 环境。这两天花时间研究了一下 Conda 的原理，发现 Conda 的原理非常简单，非常值得学习。

## Conda 的安装

在 Mac 系统中，习惯使用 `brew install ` 来安装软件，但是当你去搜索的时候, 会发现根本无法搜到 Conda 的安装包。 

```shell 

NoahGao@HW0024348 ~/D/SourceCode> brew install conda                                                                                                          (python3.10) 
==> Downloading https://formulae.brew.sh/api/formula.jws.json
#################################################################################################################################################################### 100.0%
==> Downloading https://formulae.brew.sh/api/cask.jws.json
#################################################################################################################################################################### 100.0%
Warning: No available formula with the name "conda". Did you mean confd, conan or conman?
==> Searching for similarly named formulae and casks...
==> Formulae
conda-lock                        conda-zsh-completion              confd                             conan                             conman

To install conda-lock, run:
  brew install conda-lock

==> Casks
anaconda                          coda                              miniconda                         pycharm-ce-with-anaconda-plugin   pycharm-with-anaconda-plugin

To install anaconda, run:
  brew install --cask anaconda

```

这是因为 Conda 是 Anaconda 公司开发的，而 Anaconda 公司不允许直接安装 Conda，而是通过 Anaconda 或者 miniconda 来间接安装 Conda。

> 引用: https://pypi.org/project/conda/
> 
> WARNING: Using pip install conda or easy_install conda will not give you conda as a standalone application. Currently supported install methods include the Anaconda installer and the miniconda installer. You can download the miniconda installer from https://conda.io/miniconda.html.

关于 Anaconda 和 miniconda 的区别，可以参考官方文档: https://docs.anaconda.com/distro-or-miniconda/



![alt text](./imgs/anaconda%20vs%20miniconda.png)


下载比较简单，只要根据 anaconda [官网](https://www.anaconda.com/download/success)的提示，选择对应的系统，然后下载对应的安装包，然后按照提示安装即可。 

当你完成安装后，在终端输入 `which conda` 命令，如果显示 Conda 的安装路径，则说明安装成功。

```shell
NoahGao@HW0024348 ~/D/SourceCode> which conda 
/opt/anaconda3/condabin/conda
```

通过可以观察到 Conda 的安装路径是 `/opt/anaconda3/condabin/conda`，这个路径是 Conda 的安装路径，可以进去看看它的目录结构

![alt text](./imgs/anaconda%20list.png)


## Conda 原理

在解释 conda 原理之前，先说下系统环境变量以及顺序, 当你在终端输入 `echo $PATH` 命令时，会看到:

```shell
NoahGao@HW0024348 ~/D/SourceCode> echo $PATH 
/opt/anaconda3/bin /opt/anaconda3/condabin /opt/homebrew/bin /Users/NoahGao/Library/Android/sdk/platform-tools /usr/local/bin /System/Cryptexes/App/usr/bin /usr/bin /bin /usr/sbin /sbin /var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin /var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin /var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin /Library/Apple/usr/bin /usr/local/MacGPG2/bin
```
当你安装了 Anaconda 后，会自动将 Anaconda 的 `/opt/anaconda3/condabin` 路径添加到系统环境变量中，所以你可以在终端中直接使用 conda 命令。

**同样的，系统会根据你的设置的环境变量顺序来查找命令**


当使用 `conda create -n env_name` 创建环境时，使用 `conda activate env_name` 激活环境时，系统会自动将环境目录添加到 $PATH 的头部，从而达到切换环境的效果。


## 注意

有时候发现无法切换成功，可以使用 `echo $PATH` 命令查看 PATH 环境变量顺序，如果 conda 目录不是在前面，可以使用 `conda init` 命令将 conda 目录添加到 PATH 环境变量，**新开**一个终端即可看到效果





