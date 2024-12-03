apt-get update
apt-get install vim iputils-ping wget procps \
        git  python3-pip python-pip
apt-get install libgoogle-glog-dev libdw-dev \
        libopenblas-dev gfortran
apt install autoconf automake libtool curl make g++ unzip

apt install ros-melodic-tf ros-melodic-rviz
apt install libopencv-dev python3-opencv libeigen3-dev
# pip3 install empy pygame

packages='libsdl2-2.0 xserver-xorg libvulkan1 libomp5'
apt-get update
DEBIAN_FRONTEND=noninteractive apt-get install -y $packages --no-install-recommends

apt clean
rm -rf /var/lib/apt/lists/*