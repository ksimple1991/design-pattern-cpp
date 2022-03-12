# C++设计模式

## 什么是设计模式
“每一个模式描述了一个在我们周围不断重复发生的问题，以及该问题的解决方案的核心。这样，你就能一次又一次地使用该方案而不必做重复劳动”。 ——Christopher Alexander

## 为什么要学习设计模式

### 代码评价指标
- 可维护性
- 可读性
- 可扩展性
- 简洁
- 可复用性


## 设计原则
- 开闭原则（Open Close Principle）
- 里氏代换原则（Liskov Substitution Principle）
- 依赖倒转原则（Dependence Inversion Principle）
- 接口隔离原则（Interface Segregation Principle）
- 迪米特法则，又称最少知道原则（Demeter Principle）
- 单一功能原则（Single responsibility principle）

## 设计模式

### 从目的对模式分类

#### 创建型模式
创建型（Creational）模式：将对象的部分创建工作延迟到子类或者其他对象，从而应对需求变化为对象创建时具体类型实现引来的冲击。

- 工厂模式(Factory Pattern)
- 抽象工厂模式(Abstract Factory Pattern)
- 单例模式(Singleton Pattern)
- 建造者模式(Builder Pattern)
- 原型模式(Prototype Pattern)

#### 结构型模式
结构型（Structural）模式：通过类继承或者对象组合获得更灵活的结构，从而应对需求变化为对象的结构带来的冲击。

- 适配器模式
- 桥接模式
- 过滤器模式
- 组合模式
- 装饰器模式
- 外观模式
- 享元模式
- 代理模式

#### 行为型模式
行为型（Behavioral）模式：通过类继承或者对象组合来划分类与对象间的职责，从而应对需求变化为多个交互的对象带来的冲击。

- 责任链模式
- 命令模式
- 解释器模式
- 迭代器模式
- 中介者模式
- 备忘录模式
- 观察者模式
- 状态模式
- 空对象模式
- 策略模式
- 模板模式
- 访问者模式

### 从封装变化角度对模式分类

- 组件协作
  - Template Method
  - Strategy
  - Observer/Event
- 单一职责
  - Decorator
  - Bridge
- 对象创建
  - Factory Method
  - Abstract Factory
  - Prototype
  - Builder
- 对象性能
  - Singleton
  - Flyweight
- 接口隔离
  - Facade
  - Proxy
  - Mediator
  - Adapter
- 状态变化
  - Memento
  - State
- 数据结构
  - Composite
  - Iterator
  - Chain of Resposibility
- 行为变化
  - Command
  - Visitor
- 领域问题
  - Interpreter


## 参考

[wiki/Software_design_pattern](https://en.wikipedia.org/wiki/Software_design_pattern)

[JakubVojvoda/design-patterns-cpp](https://github.com/JakubVojvoda/design-patterns-cpp)

[liu-jianhao/Cpp-Design-Patterns](https://github.com/liu-jianhao/Cpp-Design-Patterns)

[C++ 设计模式 李建忠](https://www.youtube.com/playlist?list=PLE0JTxLz7jTR2e8nAyV9vPIqH5NNxlI3N)

[C++ 设计模式 (李建忠视频笔记)](https://miaopei.github.io/2016/07/16/Program-C/C++%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F%E6%9D%8E%E5%BB%BA%E5%BF%A0%E7%AC%94%E8%AE%B0/)

