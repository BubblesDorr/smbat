#! /bin/bash
cd ~
cd workspace/lib/BLAS-3.12.0
# 使用gfortran编译器编译fortran源码
gfortran -O3 -std=legacy -m64 -fno-second-underscore -fPIC -c *.f
# 创建静态库
ar r libfblas.a *.o
# 为静态库libfblas.a生成符号表
ranlib libfblas.a
# 删除编译产生的中间文件
rm -rf *.o     
# 更新环境变量
# todo 优化并测试效果
export BLAS=/home/smbat/workspace/lib/BLAS-3.12.0/libfblas.a
# echo 'export BLAS=/home/smbat/workspace/lib/BLAS-3.12.0/libfblas.a' \
#     >> ~/.bashrc
# 刷新环境变量
# source ~/.bashrc