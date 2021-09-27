#! /bin/sh
export LD_LIBRARY_PATH="/lib/"
export > /tmp/test.txt
exec -a "$0" "/home/xcl/Documents/my/qt/QDBusDemo/build/Server/Server" "$@"