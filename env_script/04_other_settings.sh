#! /bin/bash

# 设置ros环境变量
cd /home/admin
rm .bashrc
touch .bashrc
echo 'source /opt/ros/$ROS_DISTRO/setup.bash' >> .bashrc
# 设置workspace环境变量
echo 'export workspace=/home/admin/workspace' >> .bashrc
# 设置项目环境变量
echo 'export smbat=/home/admin/workspace/src/smbat' >> .bashrc

echo 'export PATH=$PATH:/home/admin/lib/sumo-1.16.0/bin' >> .bashrc
echo 'export SUMO_HOME=/home/admin/lib/sumo-1.16.0' >> .bashrc
echo 'export PATH=$PATH:/home/admin/.local/bin'
echo 'alias python='python'' >> .bashrc

source .bashrc

# 批量设置脚本权限
# docker
# chmod -R +x docker
# # env_script
# chmod -R +x env_script