# 1 环境配置
## 1.1 前提条件
ubuntu18.04以上，安装nvidia-docker

## 1.2 安装流程
### 1.2.1 拉取项目文件
+ 在主目录下创建dockershare和workspace文件夹

```shell
cd ~
mkdir -p dockershare/workspace
```

+ 进入工作空间，拉取项目文件

```shell
cd dockershare/workspace
git clone git@github.com:xutao543210/smbat.git # todo modify the project address
```

### 1.2.2 创建镜像和容器
+ 创建docker镜像

```shell
cd smbat/docker

sudo chmod +x 01_build_images.sh 02_run_containers.sh # 增加可执行权限

./01_build_image.sh # 创建项目镜像，第一次运行需要拉取基镜像，时间较长

./02_run_container.sh # 基于镜像创建容器，默认容器名smbat
# or ./02_run_container.sh your_container_name
```

### 1.2.3 容器内环境配置
+ 进入容器，赋予脚本权限

```shell
docker exec -it smbat bash
cd workspace/smbat
sudo chmod -R +x env_script
```

+ 进入脚本目录，依次执行脚本

```shell
cd env_script
sudo ./01_install_deps.sh
sudo ./02_down_libs.sh # 如果下载失败，手动执行脚本内命令
sudo ./03_install_libs.sh
sudo ./04_other_settings.sh
```

