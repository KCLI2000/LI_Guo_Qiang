## Pilot
- Author: mafp
- Date: 2019/11/16
- Version: 1.1.2

## 架构说明
所有源文件放在`src`目录下，`pilot_node.cpp`是主文件,main函数在里面。 `pilot_node_api.cpp`包含了几乎所有的函数定义，`pilot_node_control.cpp`包含了控制函数的定义。  
无人机的所有信息都存储在`Pilot`类的实例中，为防止误修改，所有的变量都不是公有的，直接操作变量是不允许的，外部必须通过类成员函数获取或修改这些变量。  
## 命名规范
这个命名规范只是我个人的习惯，在这里说一下方便大家看懂。  
```cpp
xxx_pull() //表示获取某个状态信息
update_xxx()//表示更新某个状态信息
aaa_xxx_callback()//表示回调函数

```