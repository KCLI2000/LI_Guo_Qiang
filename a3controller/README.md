## A3 Flight Controller
- Author: mafp
- Date: 2019/11/16
- Version: 1.1.2

### 依赖库
- DJI SDK CORE
- DJI SDK ROS

### 怎么操作
```
git clone https://titanx.liuyinyi.cn/mafp/A3Controller.git
cd A3Controller

// 编译dji sdk 
cd src/Onboard-SDK
mkdir build && cd build
cmake ..
make djiosdk-core
sudo make install

//然后到顶层目录A3Controller下
catkin_make
```

### 代码规范
代码架构如下：
```
├── README.md (说明文档)
└── src (各个包package的主文件)
    ├── CMakeLists.txt 
    ├── Onboard-SDK
    ├── Onboard-SDK-ROS
    └── pilot (飞控)
```
### 控制接口
控制接口包括控制无人机的起飞降落，水平和垂直方向的移动  
通过将指令发布到 `pilot/pilot_ctrl_api` 结点实现控制  
消息是`pilot_ctrl_cmd`，格式为 1个string类型的**cmd**，3个float类型的**x，y，z**    


|cmd|x|y|z|作用|
|---|---|---|---|---|
|takeoff|None|Npne|None|使飞机起飞|
|hovering|None|None|None|使飞机悬停|
|moving|x|y|None|飞到同一水平面指定位置||
|climbing|None|None|z|飞到指定高度z|
|landing|None|None|None|使飞机降落|  


### 可能的错误
1. 可能会缺少 nmea_msgs，解决方法如下：
```
sudo apt install ros-(your ros version)-nmea-msgs
```

### 注意事项
1. 飞机的参考系是FLU或者NEU，这取决于控制指令标志位的设置，在模拟器中仿真时，飞行的参考系的x，y轴与实际相反。理论上飞机的参考坐标系为NEU时，x轴并不是机头，参考系为FLU时，理论上x轴是机头，然鹅仿真中有偏差，实际上有待测试。
2. 测试流程必须严格保障安全，每次测试至少需要两人，最好有四人协同操作。任何修改的代码必须现在模拟器上测试没有明显问题后才能上机器测试。不能直接上`M600`测试，每次必须先在小飞机上测试无问题后再上大飞机。
3. 代码还未详细注释，后续有空补充，希望大家写的代码能够让每个人都看懂。