# Observer
观察者模式(Observer Pattern)也叫做发布订阅模式(Publish/Subscribe)。

## 定义
> Observer defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically. Then pattern has behavioral purpos and applies to the objects.

定义对象间一种一对多的依赖关系，使得每当一个对象状态改变，则所有依赖于它的对象都会得到通知并制动更新

## 实现
### Subject 被观察者
定义被观察者必须实现的职责，它必须能够动态的增加、取消观察者。它一般是抽象类或者是实现类，仅仅完成作为被观察者必须实现的职责：管理观察者并通知观察者。

### Observer 观察者
观察者接收到消息后，即进行update(更新方法)操作，对接收到的消息进行处理

### ConcreteSubject 具体的被观察者
定义被观察者自己的业务逻辑，同时定义对哪些时间进行通知。

### ConcreteObserver 具体的观察者
每个观察者有自己独立的处理逻辑。

## 应用

### 优点
- 观察者和被观察者之间是抽象耦合。
- 建立一套触发机制。

### 缺点
- 多个观察者时，一个观察者卡顿会影响整体的执行效率。一般采用异步的方式。

### 使用场景
- 关联行为场景
- 事件多级触发场景
- 跨系统的消息交换场景，如消息队列的处理机制

- when an abstaction has two aspects, one dependent on the other
- when a change to one object requires changing other, and you don't know how many objects need to be changed
- when an object should be able to notify other objects without making assumptions about who these objects are