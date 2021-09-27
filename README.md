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
   * mkdir build && cd build
   * qmake .. && make
   * cd Client && ./Client
   * cd Server && ./Server