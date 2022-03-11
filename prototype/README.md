# Prototype

## 定义
> Specify the kinds of objects to create using a prototypical instance, and create new objects by copying this prototype. Pattern has creational purpose and deals with object relationships, which are more dynamic. The pattern hides the complexities of making new instances from the client.

如果对象的创建成本比较大，而同一个类的不同对象之间差别不大（大部分字段都相同），在这种情况下，我们可以利用对已有对象（原型）进行复制（或者叫拷贝）的方式来创建新对象，以达到节省创建时间的目的。这种基于原型来创建对象的方式就叫作原型设计模式（Prototype Design Pattern），简称原型模式。

## 实现



## 应用
- when the classes to instantiate are specified at run-time
- to avoid building a class hierarchy of factories that parallels the class hierarchy of products
- when instances of a class can have one of only a few different combinations of state

### 注意事项
原型模式有两种实现方法，深拷贝和浅拷贝。浅拷贝只会复制对象中的基本数据类型数据和引用对象的内存地址，不会复制引用对象，以及引用对象的引用对象。而深拷贝得到的是一份完完全全独立的对象。所以，深拷贝比浅拷贝更加耗时，更加耗内存空间。
- 对于不可变对象，浅拷贝
#### 深拷贝

#### 浅拷贝