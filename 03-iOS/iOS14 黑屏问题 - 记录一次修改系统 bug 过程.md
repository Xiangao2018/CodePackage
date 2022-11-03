# iOS14 黑屏问题 | 记录一次修改系统 bug 过程

标签（空格分隔）： iOS 感悟

---

[TOC]

## 一、现象

当升级 iPad 系统到最新的 14.0.1 时候，线上 App 启动后变为黑屏状态

## 二、解决思路

因为以前就遇到过黑屏情况，本以为这次也是简单的问题。打开项目查看，项目使用的是 LaunchScreen.storyboard 里面加一个全屏的 UIImageView 处理，看起来没有任何问题；

### 2.1 检查步骤：

+ 检查启动图名称(ScreenImage)，与 launch 无关；随机改名测试，现象依旧存在; -> 失败

+ 检查启动图位置，跟目录下面，不在 Images.xcassets 下(以前社区中有人因为图片放在 Images.xcassets而黑屏)-> 反过来配置到 Images.xcassets，现象依旧存在； -> 失败

+ 检查启动图尺寸（2732 * 2732）， 2732 是 iPad Pro 12.9 的尺寸，没啥问题；

+ 检查重装 App, 重启设备等反复操作，现象依旧存在 -> 失败；

上述基本步骤查完意识到，这可能不是一个简单的黑屏问题，实时也是如此；

### 2.2 Demo 验证

为了验证项目是否配置错误或者缓存等其他原因，我新建了一个 Demo 来验证；

使用 Xcode 12.0 新建一个项目，在 LaunchScreen.storyBoard 加一个全屏的 UIImageView, 配置好，将项目中 2732 * 2732 的启动图拉过来，模拟器运行；

**这 TM 也黑屏;**

**这 TM 也黑屏;**

**这 TM 也黑屏;**

### 2.3 控制台应用分析

在[这篇文章](https://www.ershicimi.com/p/bdb29c5a139bdbffff0a26157df79d8d)中详细解释了启动图的加载流程:

> 查找沙盒目录中是否存在可用的缓存启动图，如果有则直接使用，否则执行下一步；

> 根据 LaunchScreen.storyboard 生成新的启动图，并将其缓存至沙盒目录/Library/SplashBoard/Snapshots/<Bundle identifier> - {DEFAULT GROUP}/

在实际测试中，反复测试进行比对的时候，系统均无法生成对应的图片:

![](https://gitee.com/rsenjoyer/Pictures/raw/master/img/Snip20201019_10.png)

这隐隐猜测到，这可能是个**系统的Bug**；

### 2.4 查阅官方文档

在[Github 这个 issue](https://github.com/apache/cordova-ios/issues/990)中提到，iOS 14.0 之后有[UILaunchScreen](https://developer.apple.com/documentation/bundleresources/information_property_list/uilaunchscreen) 新的启动方式，查看官方文档，文档指出:

> **Note**
> Use this key to configure the user interface during app launch in a way that doesn’t rely on storyboards. If you prefer to use storyboards, use [UILaunchStoryboardName](https://developer.apple.com/documentation/bundleresources/information_property_list/uilaunchstoryboardname) instead.

理论上分析，苹果文档这么说明，应该是可以使用 UILaunchStoryboardName 的启动方式，但实际上不行。

尝试 UILaunchScreen + uilaunchstoryboardname 组合方式进行配置，得出如下结论：

+ 单独使用 UILaunchScreen 无法适配 iOS14 以下系统；

+ 单独使用 UILaunchScreen 很难适配 iOS14 以上不同屏幕, 启动图容易拉伸或压缩；

+ 同时使用 UILaunchScreen + uilaunchstoryboardname 方案依旧没有解决；

### 2.5 面向 Google 编程

在苹果社区的[这个讨论](https://developer.apple.com/forums/thread/650913)与[这个讨论](https://developer.apple.com/forums/thread/658030)中都讨论了黑屏问题，但大多都没有实质的解决方案，在 Stack Overflow 的[这个提问](https://stackoverflow.com/questions/63978396/launch-screen-not-working-on-ios-14-with-xcode-12)中提到，**更改图片尺寸来处理**。

通过尝试修改图片尺寸(测试为：2400 * 2400)与格式(jpg)，反复测试后得出如下结论：

+ **启动图流程正常，能够向沙盒中写入图片**；

+ **有一定几率**启动成功，但仍有可能会失败；

![](https://gitee.com/rsenjoyer/Pictures/raw/master/img/Snip20201019_8.png)

### 2.6 解决方案

**方案一：**

在实际测试中，结合[这篇文章](https://www.ershicimi.com/p/bdb29c5a139bdbffff0a26157df79d8d)提到的替换启动图方案 + 改变原来 2732 * 2732 png 的图片是可以解决掉这个问题的。

但由于我们实际项目 ToC，而且这种做法不是官方标准方案，因此没有采用，最终仅仅做了图片大小改为 2400 * 2400(这方案一定几率还是会失败)。

**方案二：**

如果项目中启动页是纯色 + Logo 等形式，你可以使用 StoryBoard 背景纯色 + logo 等形式处理。这种方案简单测试下，应该可行。

这种方案需要注意图片大小（2732 * 2732.png) 很容易失败；

单由于我们启动图是张渐变的图片，因此该方案不可取。


## 三、其他问题

在实际测试中，如果你使用的不是满屏的图片，这种出现的概率较低。（不是没有，有朋友遇到了，是概率低）。

有尝试背景纯色+Logo+满屏启动图方案，希望如果未成功，损失渐变效果。实际测试中，如果是满屏图片，启动图未成功就是黑屏状态，不会透过满屏显示 Logo + 纯色背景。

**卸载 App，然后立马重新装 App，系统大概率还没有回收掉那部分的进程，因此连续测试很容易得到连续失败或者连续成功情况**

**卸载 App，然后立马重新装 App，系统大概率还没有回收掉那部分的进程，因此连续测试很容易得到连续失败或者连续成功情况**

**卸载 App，然后立马重新装 App，系统大概率还没有回收掉那部分的进程，因此连续测试很容易得到连续失败或者连续成功情况**


我在苹果社区提了一个相关问题：[iOS 14.0.1 LaunchScreen black when start app](https://developer.apple.com/forums/thread/664511)，如果有遇到并解决掉这个问题的，麻烦在本文下或者苹果社区回复下，非常感谢！

That is All！


![](https://gitee.com/rsenjoyer/Pictures/raw/master/img/20201022171215.png)
![](https://gitee.com/rsenjoyer/Pictures/raw/master/img/20201022163754.png)
![](https://gitee.com/rsenjoyer/Pictures/raw/master/img/20201022190328.png)


