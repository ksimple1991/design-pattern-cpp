# Iterator Pattern
## 定义
> Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.
> 
> 提供一种方法访问一个容器对象中的各个元素，而又不需暴露该对象的内部细节。

迭代器模式(Iterator Pattern)，也叫作游标模式(Cursor Pattern)，用于遍历容器，比如数组、链表、树、图、跳表。它将集合对象的遍历操作从集合类中拆分出来，放在迭代器类中，让两者的职责更加单一。

## 应用
### 优点
- 对于复杂的数据结构（比如树、图）来说，有各种复杂的遍历方式。如果客户端代码来实现遍历算法，势必增加开发成本，且容易写错
- 遍历逻辑写到容器类中会增加容器类代码的复杂性
- 每个迭代器独享游标信息，这样可以创建多个迭代器，同时对同一个容器遍历而互不影响
- 容器和迭代器都提供了抽象的接口，方便我们开发时基于接口而非具体实现编程。如更换、添加遍历算法时，只需拓展新的迭代器类即可，更符合开闭原则

### 实现

#### Iterator抽象迭代器
抽象迭代器负责定义访问和遍历元素的接口，基本上有固定的3个方法：
- first()，获取第一个元素
- next()，访问下一个元素
- hasNext()，是否已经访问到底部
- currentItem()，当前元素

#### ConcreteIterator具体迭代器
实现迭代器接口，完成容器元素的遍历

#### Aggregate抽象容器
负责创建具体迭代器角色的接口，必然提供一个类似createIterator()这样的方法

#### ConcreteAggregate具体容器
实现容器接口定义的方法，创建出容纳迭代器的对象

### 应用场景
- to access an aggregate object's contents without exposing its internal representation（访问聚合对象的内容而不暴露其内部表示）
- to support multiple traversals of aggregate objects（支持聚合对象的多次遍历）
- to provide a uniform interface to traversing different aggregate structures(to support polymorphic iteration)。为遍历不同的聚合结构提供统一的遍历接口（支持多态迭代）
