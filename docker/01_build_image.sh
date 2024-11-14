#!/bin/bash
# Build the SMBAT image

if [ "$#" -eq 1 ]; then
    image_name=$1
else
    image_name=dorrproject/smbat
fi

nvidia-docker build -t $image_name -f Dockerfile .