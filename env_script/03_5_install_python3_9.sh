#! /bin/bash

apt install build-essential zlib1g-dev libncurses5-dev \
    libgdbm-dev libnss3-dev libssl-dev libreadline-dev \
    libffi-dev wget libbz2-dev

cp /home/admin/workspace/download/Python-3.9.0.tgz /home/admin/lib/
cd /home/admin/lib/
tar -xf Python-3.9.0.tgz
rm Python-3.9.0.tgz
cd Python-3.9.0
./configure --enable-optimizations
make -j $(nproc)
make altinstall
update-alternatives --install /usr/bin/python3 python3 /usr/local/bin/python3.9 1
update-alternatives --config python3