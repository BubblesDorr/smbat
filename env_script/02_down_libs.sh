#! /bin/bash
cd ~
mkdir -p workspace/download
cd workspace/download

echo "download the ma27"
git clone https://github.com/HITSZ-LeggedRobotics/ma27.git

echo "download the OOQP"
git clone https://github.com/emgertz/OOQP.git

echo "download the blas"
wget http://www.netlib.org/blas/blas.tgz

echo "download the protobuf"
PROTOBUF_URL="https://github.com/protocolbuffers/protobuf/releases/download/v21.12"
PROTOBUF_NAME="protobuf-all-21.12.zip"
wget "$PROTOBUF_URL/$FILE_NAME"