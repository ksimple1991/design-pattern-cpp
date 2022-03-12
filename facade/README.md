# Façade Pattern

## 定义
> Provide a unified interface to a set of interfaces in a subsystem. Facade  defines a higher-level interface that makes the subsystem easier to use.

要求一个子系统的外部与其内部的通信必须通过一个统一的对象进行。门面模式提供了一个高层次的接口，使得子系统更易于使用。

## 实现

### Façade 门面角色
客户端可以调用这个角色方法，此角色知晓子系统的所有功能和责任。一般情况下，本角色会将所有从客户端发来的请求委派到相应的子系统去。

### subsystem 子系统角色
对于子系统而言，门面仅仅是另外一个客户端。可以同时有一个或多个子系统。


## 应用

### 要点
- 从客户程序来看，Façade模式简化了整个组件系统的接口，对于组件内部和外部的客户程序来说，达到一种“解耦”的效果--内部子系统的任何变化不会影响到Façade接口的变化。
- Façade设计模式更注重架构的层次去看整个系统，而不是单个类的层次。Façade很多时候是一种架构模式。

## 扩展

### “接口隔离”模式
在组件构建过程中，某些接口之间直接的依赖常常会带来很多问题，甚至根本无法实现。采用添加一层**间接**（稳定）接口，来隔离本来互相紧密关联的接口是一种常见的解决方案。

### 典型模式
- Façade
- Proxy
- Adapter
- Mediator

