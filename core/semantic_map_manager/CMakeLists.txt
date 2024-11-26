cmake_minimum_required(VERSION 2.8)
project(semantic_map_manager)

set(CMAKE_VERBOSE_MAKEFILE "true")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11  -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")

find_package(catkin REQUIRED COMPONENTS
    roscpp
    visualization_msgs
    sensor_msgs
    geometry_msgs
    tf
)

find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(common REQUIRED)
find_package(motion_predictor REQUIRED)
find_package(vehicle_msgs REQUIRED)
find_package(vehicle_model REQUIRED)

set(THIRD_PARTY_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/thirdparty)

#if this catkin packge's header is used by other packages, use catkin_package to
#declare the include directories of this package.
catkin_package(
    INCLUDE_DIRS include ${vehicle_msgs_INCLUDE_DIRS} ${vehicle_model_INCLUDE_DIRS} ${THIRD_PARTY_INCLUDE_DIRS} ${motion_predictor_INCLUDE_DIRS}
    LIBRARIES planning_smm planning_smm_ros
)

include_directories(
    include
    ${THIRD_PARTY_INCLUDE_DIRS}
    ${vehicle_msgs_INCLUDE_DIRS}
    ${vehicle_model_INCLUDE_DIRS}
    ${common_INCLUDE_DIRS}
    ${motion_predictor_INCLUDE_DIRS}
    ${catkin_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    ${OpenCV_INCLUDE_DIRS}
)

add_library(planning_smm
    src/semantic_map_manager/semantic_map_manager.cpp
    src/semantic_map_manager/data_renderer.cpp
    src/semantic_map_manager/config_loader.cpp
    src/semantic_map_manager/traffic_signal_manager.cpp
)
target_link_libraries(planning_smm
    ${vehicle_model_LIBRARIES}
    ${common_LIBRARIES}
    ${motion_predictor_LIBRARIES}
    ${OpenCV_LIBS}
)

add_library(planning_smm_ros
    src/semantic_map_manager/ros_adapter.cpp
    src/semantic_map_manager/visualizer.cpp
)
target_link_libraries(planning_smm_ros
    ${catkin_LIBRARIES}
    planning_smm
)


#install the hearder files so that other packages can include.
#install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
 #  DESTINATION ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_INCLUDE_DESTINATION}/
 #  FILES_MATCHING PATTERN "*.h"
 #  PATTERN ".svn" EXCLUDE
#)
