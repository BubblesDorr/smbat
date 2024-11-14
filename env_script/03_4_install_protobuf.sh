#! /bin/bash
cd ~
cd workspace/lib/protobuf-21.12
# 配置编译选项
./configure
# 编译
make 
# 安装
make install
# 更新动态库缓存
ldconfig