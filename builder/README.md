# Builder

## 定义
> Separate the construction of a complex object from its representation so that the same construction process can create different representations.

将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。


## 实现

### Product 产品类
通常是实现了模板方法模式。

### Builder 抽象建造者
规范产品的组建，一般由子类实现。

### ConcreteBuilder 具体建造者
实现抽象类定义的所有方法，并且返回一个组建号的对象。

### Director 导演类
负责安排已有模块的顺序，然后告诉Builder开始建造。

## 应用


### 优点
- 封装性
- 建造者独立，容易扩展
- 便于控制细节风险


### 注意事项
- 建造者模式关注的是零件类型和装配工艺（顺序）。工厂方法重点则是创建，创建零件是它的主要职责，组装顺序不是它关心的。

