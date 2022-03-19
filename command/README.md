# Command Pattern

## 定义
> Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

将请求封装成一个对象，从而让你使用不同的请求把客户端参数化，对请求排队或者记录请求日志，可以提供命令的撤销和恢复功能。

## 实现

### Receive 接收者角色
负责执行具体的命令。

### Command 命令角色
声明需要执行的所有命令。

### Invoker 调用者角色
接收到命令，并执行命令。

## 应用

### 优点
- 类间解耦。
- 可扩展性好。
- 命令模式可结合其他模式。

### 缺点
- 命令较多时，Command子类将会膨胀。
