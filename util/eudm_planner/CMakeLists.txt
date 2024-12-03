cmake_minimum_required(VERSION 2.8)
project(eudm_planner)

set(CMAKE_VERBOSE_MAKEFILE "true")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11  -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")

find_package(catkin REQUIRED COMPONENTS
    roscpp
    visualization_msgs
    sensor_msgs)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(common REQUIRED)
find_package(vehicle_model REQUIRED)
find_package(semantic_map_manager REQUIRED)
find_package(forward_simulator REQUIRED)
find_package(route_planner REQUIRED)
find_package(Protobuf REQUIRED)

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS
    proto/eudm_config.proto
)

#if this catkin packge's header is used by other packages, use catkin_package to
#declare the include directories of this package.
catkin_package(
    INCLUDE_DIRS include ${CMAKE_CURRENT_BINARY_DIR}
    LIBRARIES pp_eudm pp_eudm_ros
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${common_INCLUDE_DIRS}
    ${route_planner_INCLUDE_DIRS}
    ${semantic_map_manager_INCLUDE_DIRS}
    ${vehicle_model_INCLUDE_DIRS}
    ${forward_simulator_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_library(pp_eudm
    src/eudm_planner/eudm_planner.cpp
    src/eudm_planner/map_adapter.cpp
    src/eudm_planner/eudm_manager.cpp
    src/eudm_planner/dcp_tree.cpp
    ${PROTO_SRCS}
)
target_link_libraries(pp_eudm
    pp_smm
    pp_forward_simulator
)

add_library(pp_eudm_ros
    src/eudm_planner/eudm_server_ros.cpp
)
target_link_libraries(pp_eudm_ros
    pp_eudm
    pp_smm_ros
)

#install the hearder files so that other packages can include.
#install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
 #  DESTINATION ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_INCLUDE_DESTINATION}/
 #  FILES_MATCHING PATTERN "*.h"
 #  PATTERN ".svn" EXCLUDE
#)
