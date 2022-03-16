# Visitor

## 定义
> Represent an operationt to be performed on the elements of an object structure. Visitor lets you define a new operation without changing the classes of the elements on which it operates.

表示一些作用于某种数据结构中的各元素的操作，它可以在不改变数据结构的前提下定义作用于这些元素的新的操作。

## 实现

### Visitor 抽象访问者
抽象类或者接口，声明访问者可以访问哪些元素，具体到程序中就是visit方法的参数定义哪些对象是可以被访问的。

### ConcreteVisitor 具体访问者
它影响访问者访问到一个类后该怎么干，要做什么事情。

### Element 抽象元素
声明接受哪一类访问者访问，程序上是通过accept方法中的参数来定义的。

### ConcreteElement 具体元素
实现accept方法。

### ObjectStructure 结构对象
元素生产者，一般容纳在多个不同类、不同接口的容器。

## 应用

### 优点
- 符合单一职责原则。
- 优秀的扩展性。
- 灵活性非常高。

### 缺点
- 具体元素对访问者公布细节
- 具体元素变更比较困难
- 违背了依赖倒置原则。直接依赖实现类，扩展比较难。

### 使用场景

