

# Actor编程模型

ActorManager - 负责调度工作线程执行Actor的任务
Actor - 负责添加任务到任务队列
ActorTask - 负责保存任务处理函数 任务参数

ActorTask 如何保存处理函数和任务参数？

## 添加任务

- 添加无参任务

- 添加有参任务

代码实践

- 在外部调用

- 使用宏

- 在内部调用

## 注意事项

- task是异步执行的，因此要保证执行任务时Actor对象还存在

- 同一个actor的任务是按照push的顺序执行的

## 存在问题

- 由模板实现 ActorTask 参数序列化，编译出错时会导致很长的报错，难以阅读

- 多个线程对同一个actor push任务 那么任务的执行顺序是不能保证的 因为多个线程push操作本来就是没有先后顺序的

- 由于C++缺乏反射机制，所以需要使用宏和模板来简化代码

- 使用 PUSH_TASK_EX 宏会值捕获参数，使用不当会存在效率问题

## 设计难点

- 配置表模块的重读功能

多个线程会同时访问配置表，如何实现重读配置功能。

在C++中会比较麻烦，因为没有自动内存管理，重读后旧指针必须自己想办法维护。