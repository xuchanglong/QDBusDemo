#! /bin/sh
echo "--- 正在生成接口文件 ---"
cd ../__interfaces 
qdbusxml2cpp msgInterface.xml -i interfaceTypeDefine.h -p msgInterface
echo "--- 接口文件生成成功 ---"
cd ../build
echo "--- 正在编译 ---"
qmake .. && make
echo "--- 编译成功 ---"
echo "--- 正在配置 QDBus ---"
sudo cp com.xcl.test.conf /etc/dbus-1/system.d
workdir=$(cd $(dirname $0); pwd)
echo "[D-BUS Service]
Name=com.xcl.test
Exec=$workdir/Server/Server
User=root" > com.xcl.test.service
sudo cp com.xcl.test.service /usr/share/dbus-1/system-services
echo "--- 配置 QDBus 成功 ---"
echo "\e[1;32m 完成" $(tput sgr0)