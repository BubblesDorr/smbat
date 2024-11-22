#! /bin/bash
cp -r /home/admin/workspace/download/ma27 /home/admin/lib/
cd /home/admin/lib/ma27/ma27-1.0.0

# 执行配置脚本
bash ./configure CPPFLAGS="-fPIC" CFLAGS="-fPIC" FFLAGS="-fPIC"
# 将生成的可执行文件、库文件安装到系统目录
make install