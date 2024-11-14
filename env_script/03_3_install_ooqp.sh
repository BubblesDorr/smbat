#! /bin/bash
cd ~
cd workspace/lib/OOQP
cp -r ~/workspace/lib/ma27/ma27-1.0.0/src/libma27.a lib
./configure
make
make install