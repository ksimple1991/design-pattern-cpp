# Composite Pattern

## 定义
> Compose objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

将对象组合成树形结构以表示“部分-整体”的层次结构，使得用户对单个对象和组合对象的使用具有一致性。

## 实现

### Component 抽象构件角色
定义参加组合对象的共有方法和属性，可以定义一些默认的行为或属性。

### Leaf 叶子构件
叶子对象，其下再没有其他分支，也就是遍历的最小单位。

### Composite 树枝构件
树枝对象，它的作用是组合树枝节点和叶子节点形成一个树形结构。

## 应用
### 优点
- 高层模块调用简单。
- 节点自由增加

### 缺点
- 高层直接使用了实现类，违反了依赖倒置原则，限制了接口的影响范围。

### 使用场景
- 维护和展示部分-整体关系的场景，如树形菜单、文件和文件夹管理。
- 从一个整体中能够独立出部分模块或功能的场景。
