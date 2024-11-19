#!/bin/bash
# Build the smbat container
if [ "$#" -eq 1 ]; then
    container_name=$1
else
    container_name=smbat
fi

docker run \
    --gpus all \
    --privileged \
    --net host \
    -e DISPLAY=:0 \
    --name  $container_name \
    --mount type=bind,source=/home/$USER/docker_share/workspace,target=/home/admin/workspace \
    -itd \
    dorrproject/smbat \
    /bin/bash