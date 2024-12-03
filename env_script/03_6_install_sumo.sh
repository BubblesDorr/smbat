#! /bin/bash
apt update
apt-get install cmake python g++ libxerces-c-dev \
        libfox-1.6-dev libgdal-dev libproj-dev \
        libgl2ps-dev swig

cp /home/admin/workspace/download/sumo-src-1.16.0.tar.gz /home/admin/lib/
cd /home/admin/lib/
tar -zxf sumo-src-1.16.0.tar.gz
rm sumo-src-1.16.0.tar.gz
cd sumo-1.16.0

export PATH=$PATH:/home/admin/lib/sumo-1.16.0/bin
export SUMO_HOME=/home/admin/lib/sumo-1.16.0

mkdir build/cmake-build
cd build/cmake-build
cmake ../..
make -j $(nproc)