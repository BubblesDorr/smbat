#! /bin/bash
cp -r /home/admin/workspace/download/OOQP /home/admin/lib/
cd /home/admin/lib/OOQP

cp /home/admin/lib/ma27/ma27-1.0.0/src/libma27.a .
./configure
make
make install