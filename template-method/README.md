## Template Method

Define the skeleton of an algorithm in an operation, deferring some
steps to subclasses. Template Method lets subclasses redefine certain
steps of an algorithm without changing the algorithm's structure.

定义一个操作中的算法的框架，而将一些步骤延迟到子类中。使得子类可以不改变一个算法的结构
即可重定义该算法的某些特定步骤。

#### 通用类图



#### 优点
- 封装不变部分，扩展可变部分
- 提取公共部分代码，便于维护
- 行为由父类控制，子类实现

#### 缺点
模板方法中抽象类定义了部分抽象方法，由子类实现，子类执行的结果影响了父类的结果。
子类对父类产生了影响，这会带来代码阅读的难度，而且也会让新手产生不适感。


#### 使用场景
- 多个子类有公有方法，且逻辑基本相同
- 重复、复杂的算法。可以把核心算法设计为模板方法，周围的相关细节功能则由各个子类实现
- 重构时，模板方法模式是一个经常使用的模式，把相同的代码抽取到父类中，然后通过钩子函数约束其行为


#### 扩展
设置钩子函数，由子类的一个方法返回值决定公共部分的执行差异

