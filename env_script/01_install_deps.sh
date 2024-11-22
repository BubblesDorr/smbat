apt-get update
apt-get install vim iputils-ping wget procps \
        git  python3-pip python-pip
apt-get install libgoogle-glog-dev libdw-dev \
        libopenblas-dev gfortran
apt install autoconf automake libtool curl make g++ unzip

apt install ros-melodic-tf ros-melodic-rviz
apt install libopencv-dev python3-opencv libeigen3-dev
# pip3 install empy pygame

apt clean
rm -rf /var/lib/apt/lists/*