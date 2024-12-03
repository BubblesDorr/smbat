#!/bin/bash
# Build the smbat container
if [ "$#" -lt 2 ]; then
    echo "Error: This script requires at least 2 arguments."
    exit 1
fi

image_name=$1
container_name=$2

docker run \
    --name $container_name \
    --gpus all \
    -e NVIDIA_DRIVER_CAPABILITIES=all \
    -v /etc/localtime:/etc/localtime:ro \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v /usr/share/vulkan/icd.d:/usr/share/vulkan/icd.d \
    -e DISPLAY=$DISPLAY \
    -e GDK_SCALE \
    -e GDK_DPI_SCALE \
    --network="host" \
    --privileged \
    -v /dev/bus/usb:/dev/bus/usb \
    --mount type=bind,source=/home/$USER/docker_share/workspace,target=/home/admin/workspace \
    --mount type=bind,source=/software/Carla,target=/home/admin/third_party/Carla \
    --mount type=bind,source=/software/LimSim,target=/home/admin/third_party/LimSim \
    -itd \
    $image_name \
    /bin/bash

# docker run \
#     --gpus all \
#     --privileged \
#     --net host \
#     -e DISPLAY=:0 \
#     --name  $container_name \
#     --mount type=bind,source=/home/$USER/docker_share/workspace,target=/home/admin/workspace \
#     -itd \
#     $image_name \
#     /bin/bash