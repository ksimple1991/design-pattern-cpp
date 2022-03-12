# Facade Pattern

## 定义
> Provide a unified interface to a set of interfaces in a subsystem. Facade  defines a higher-level interface that makes the subsystem easier to use.

要求一个子系统的外部与其内部的通信必须通过一个统一的对象进行。门面模式提供了一个高层次的接口，使得子系统更易于使用。

## 实现

### Facade 门面角色
客户端可以调用这个角色方法，此角色知晓子系统的所有功能和责任。一般情况下，本角色会将所有从客户端发来的请求委派到相应的子系统去。

### subsystem 子系统角色
对于子系统而言，门面仅仅是另外一个客户端。可以同时有一个或多个子系统。

