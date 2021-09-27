QDbusDemo
===========================
基于 QDbus 的进程通信 Demo 。
****
	
|Author|徐昌隆|
|---|---
|E-mail|xclsoftware@163.com

****

#### 1、内容
   * 同步通信
   * 异步通信（基于 Watcher）
   * 异步通信（基于 Server 返回的信号）
#### 2、使用方法
   * cd ./__interfaces 
   * qdbusxml2cpp msgInterface.xml -i interfaceTypeDefine.h -p msgInterface
   * cd ..
   * mkdir build && cd build
   * qmake .. && make
   * cd Client && ./Client
   * cd ..
   * cd Server && ./Server

   * com.xcl.test.conf 拷贝至 /etc/dbus-1/system.d
   * com.xcl.test.service 拷贝至 /usr/share/dbus-1/system-services