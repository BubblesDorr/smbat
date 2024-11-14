#! /bin/bash

# 设置ros环境变量
echo 'source /opt/ros/$ROS_DISTRO/setup.bash' >> ~/.bashrc
# 设置workspace环境变量
echo 'export workspace=/home/smbat/workspace' >> ~/.bashrc
# 设置项目环境变量
echo 'export smbat=/home/smbat/workspace/smbat' >> ~/.bashrc

source ~/.bashrc

# 批量设置脚本权限
# docker
# chmod -R +x docker
# # env_script
# chmod -R +x env_script