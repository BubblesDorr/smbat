apt-get update
apt-get install vim iputils-ping wget procps \
        git  python3-pip
apt-get install libgoogle-glog-dev libdw-dev \
        libopenblas-dev gfortran ros-melodic-tf
apt install autoconf automake libtool curl make g++ unzip

apt install libeigen3-dev
apt install libopencv-dev python3-opencv
pip3 install empy pygame

apt clean
rm -rf /var/lib/apt/lists/*