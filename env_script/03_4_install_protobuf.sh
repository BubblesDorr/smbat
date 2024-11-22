#! /bin/bash

cp /home/admin/workspace/download/protobuf-all-21.12.zip /home/admin/lib/
cd /home/admin/lib/
unzip protobuf-all-21.12.zip
rm protobuf-all-21.12.zip

cd protobuf-21.12
# 配置编译选项
./configure
# 编译
make 
# 安装
make install
# 更新动态库缓存
ldconfig