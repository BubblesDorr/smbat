FROM ros:melodic-ros-base-bionic

# Set up a admin user first.
RUN apt-get -y update && apt-get -y install sudo
ENV uid 1000
ENV gid 1000

RUN mkdir -p /home/admin/workspace \
    && groupadd admin -g ${gid} \
    && useradd -r -u ${uid} -g admin admin \
    && echo "admin ALL=(ALL) NOPASSWD: ALL" > /etc/sudoers.d/admin \
    && chmod 0440 /etc/sudoers.d/admin \
    && chown ${uid}:${gid} -R /home/admin \
    && usermod --shell /bin/bash admin

USER admin
ENV HOME /home/admin
ENV SHELL /bin/bash
WORKDIR /home/admin
SHELL ["/bin/bash", "--login", "-c"]

RUN sudo apt-get -y update && sudo apt-get -y install --reinstall locales && sudo locale-gen en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US
ENV LC_ALL en_US.UTF-8

# Install tzdata without prompt.
RUN sudo apt-get -y --fix-missing update
ENV DEBIAN_FRONTEND=noninteractive
RUN sudo DEBIAN_FRONTEND=noninteractive DEBIAN_FRONTEND=noninteractive apt-get install -y tzdata


# 安装工具包
# RUN sudo apt update && \
#     sudo apt install -y \
#         wget build-essential zlib1g-dev libncurses5-dev libgdbm-dev libnss3-dev libssl-dev \
#         libreadline-dev libffi-dev libsqlite3-dev libbz2-dev liblzma-dev cmake \
#         libgoogle-glog-dev libdw-dev libopenblas-dev gfortran python-pip python3-pip&& \
#     sudo apt clean && \
#     sudo rm -rf /var/lib/apt/lists/*

# RUN sudo pip install empy pygame

# 安装基础包
# RUN sudo apt update && \
#     sudo apt install -y \
#         wget build-essential zlib1g-dev libncurses5-dev libgdbm-dev libnss3-dev libssl-dev \
#         libreadline-dev libffi-dev libsqlite3-dev libbz2-dev liblzma-dev cmake && \
#     sudo apt clean && \
#     sudo rm -rf /var/lib/apt/lists/*

# 将模拟器从本地转移到容器
# COPY ./repository/CARLA_0.9.13.tar.gz /home/admin/workspace/simulator
# COPY ./repository/sumo-src-1.15.0.tar.gz /home/admin/workspace/simulator
# COPY ./repository/Python-3.9.0.tgz /home/admin/workspace/simulator

# 安装carla0.9.13
# WORKDIR /home/admin/workspace/simulator

# 安装python3.9.0
# WORKDIR /home/admin/workspace/simulator
# RUN tar -xvf Python-3.9.0.tgz && \
#     cd Python-3.9.0 && \
#     ./configure --enable-optimizations && \
#     sudo make && \
#     sudo make install && \
#     sudo ln -s /usr/local/bin/python3 /usr/local/bin/python && \
#     sudo ln -s /usr/local/bin/pip3 /usr/local/bin/pip


 