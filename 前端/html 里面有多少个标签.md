
## 正文
这两天在阅读 [ZMarkupParser](https://github.com/ZhgChgLi/ZMarkupParser/tree/main)源码，里面有关于 HTML Tag 的定义，突然很好奇，HTML 一共有多少标签。

ZMarkupParser 一共支持了 122 个标签，在[官方文档目录](https://html.spec.whatwg.org/#elements-3)中一共定义支持 115 个有效 element，

+ 其中有 12 个是 HTML5 不支持，但 ZMarkupParser 支持
+ 其中有 5 个是 HTML5 支持，但 ZMarkupParser 未支持

122 - 12 + 5 = 115

```html

// HTML5 不支持，但 ZMarkupParser 支持
acronym
applet
basefont
big
center
dir
font
frame
frameset
param
strike
tt

// HTML5 支持，但 ZMarkupParser 未支持
hgroup
math
menu
search
slot

```

在[官方文档-Non-conforming features](https://html.spec.whatwg.org/#non-conforming-features) 中一共定义了 29 不支持的标签，上面的 15 个 HTML5 不支持 ZMarkupParser 支持 均在这个列表里面。

**总的来说，官方定义了 115 个有效 elements， 和 29 个 non-conforming-features。**

在实际各大资料网站中，列出的标签是大于 115 个，小于 144（115 + 29）个的，而且并不是 HTML5 支持的标签都支持的。

+ 英文版的 w3cschool 的 [HTML Tags](https://www.w3schools.com/tags/tag_comment.asp)一共有 124 个标签，与 ZMarkupParser 就差了 ` <!--...-->` 与 `<!DOCTYPE>` 这两个，并不支持 `hgroup`、`math`、`menu`、`search`与 `slot` 这五个。

+ 在中文版的 [w3cschool](https://www.w3school.com.cn/tags/index.asp) 中一共定义了 130 个标签，除了上面提到的 124 个标签，还定义了 `command`、`isindex`、`keygen`、`menu`、`menuitem` 和 `xmp` 这 6 个。



## 总结

1. 官方定义 144 个 elements, 115 个有效 elements，29 个已废弃的 elements;
2. 各大网站将 ` <!--...-->` 与 `<!DOCTYPE>` 定义为 html tag, 所以 tag 一共是 144 + 2 = 146 个；
3. 实际各大资源网站上显示的常用的 HTML Tag 可能在 120+，其中并不一定包含所有官方文档中定义的有效的。
