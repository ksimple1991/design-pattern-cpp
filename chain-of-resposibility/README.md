# Chain of Resposibility(职责链)
## 定义
> Avoid coupling the sender of a request to its receiver by giving more than one object a chance to handle the request. Chain the receiving objects and pass the request along the chain until an object handles its.

使多个对象都有机会处理请求，从而避免了请求的发送者和接收者之间的耦合关系。将这些对象连成一条链，并沿着这条链传递该请求，直到有对象处理它为止。


## 类图



## 应用
- 一个请求可能被多个对象处理，但是每个请求在运行时只能有一个接收者，如果显式指定，将必不可少地带来请求发送者与接收者的紧耦合
- 如何使请求的发送者不需要指定具体的接收者？让请求的接收者自己在运行时决定来处理请求，从而使两者解耦

### 优点
- 将请求与处理解耦，提高系统的灵活性。请求者不必知道是谁处理，处理者不必知道请求的全貌

### 缺点
- 性能问题。每个请求都是从链头遍历到链尾，特别是链比较长的时候，性能是一个非常大的问题
- 调试不便。采用类似递归的方式，调试的时候逻辑可能比较复杂

### 注意事项
- 链中节点数量需要控制，避免出现超长链的情况。可在Handler中设置一个最大的节点数量，在setNext方法中判断是否已经超过阈值

## 应用实践
职责链模式常用在框架开发中，用来实现框架的过滤器、拦截器功能，让框架的使用者在不需要修改框架源码的情况下，添加新的过滤拦截功能。这也体现了对扩展开放、对修改关闭的设计原则。

对于支持 UGC（User Generated Content，用户生成内容）的应用（比如论坛）来说，用户生成的内容（比如，在论坛中发表的帖子）可能会包含一些敏感词（比如涉黄、广告、反动等词汇）。针对这个应用场景，我们就可以利用职责链模式来过滤这些敏感词。对于包含敏感词的内容，我们有两种处理方式，一种是直接禁止发布，另一种是给敏感词打马赛克（比如，用 *** 替换敏感词）之后再发布。第一种处理方式符合 GoF 给出的职责链模式的定义，第二种处理方式是职责链模式的变体。
