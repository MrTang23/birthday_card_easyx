# birthday_card_easyx
基于easyx的生日贺卡  
这个项目很复杂。。写了一个多月。可能单纯脑子不太好使  
## 使用的编译器是vs2022，运行项目前请先下载easyx库  
***警告：个人logo请勿随意转载***  
  
这个贺卡难点在于掩码图的实现。easyx没有重载函数来加载透明背景的图片  
  
未解决的是如何同时运行两个循环，我觉得是开多线程，目前还不会，很抱歉。
  
这个项目没有用到虚函数，其实可以把basic类设置成抽象类。 
  
然后需要注意word和moving不是继承关系，word更像是一个给moving提供参数的类  
word实现文字或者图片，moving实现动画效果。详细的看代码。 
  
by:汤宗朔
