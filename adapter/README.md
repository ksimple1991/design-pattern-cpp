# Adapter Pattern (适配器模式)

适配器模式又叫做变压器模式，也叫做包装模式(Wrapper)。

## 定义
> Convert the interface of a class into another interface clients expect. Adapter lets classes work to together  that couldn't otherwise because of incompatible interfaces.

将一个类的接口变成客户端所期待的另一种接口，从而使原本因接口不匹配而无法一起工作的两个类能够一个工作。

## 角色

### Target 目标角色
该角色定义把其他类转换为何种接口，也就是我们的期望接口。

### Adaptee 源角色
它将被转换成目标角色，是已经存在的、运行良好的类或对象。

### Adapter 适配器角色
适配器模式的核心角色，适配器角色是需要新建立的，它的职责是把源角色转换为目标角色。

## 应用

### 优点
- 可以让两个没有任何关系的类在一起运行。
- 增加了类的透明性。我们访问的Target目标角色，具体的实现都委托为源角色，对高层次模块透明。
- 提高了类的复用度。源角色和目标角色可以正常使用。
- 灵活性非常好。删除适配器，其他代码都不用修改。

### 使用场景
- 系统扩展时，修改一个已经投产的接口
- 遗留代码复用、类库迁移

### 注意事项
适配器模式是为了解决正在服役的项目问题，在详细设计阶段不要考虑它，项目一定要遵守依赖倒置原则和里氏替换原则。


