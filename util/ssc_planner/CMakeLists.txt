cmake_minimum_required(VERSION 2.8)
project(ssc_planner)

set(CMAKE_VERBOSE_MAKEFILE "true")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11 -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")

find_package(catkin REQUIRED COMPONENTS
    roscpp
    visualization_msgs
    sensor_msgs)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(OpenMP REQUIRED)
find_package(common REQUIRED)
find_package(semantic_map_manager REQUIRED)
find_package(Protobuf REQUIRED)

PROTOBUF_GENERATE_CPP(PROTO_SRCS PROTO_HDRS
    proto/ssc_config.proto
)

#if this catkin packge's header is used by other packages, use catkin_package to
#declare the include directories of this package.
catkin_package(
    INCLUDE_DIRS include ${CMAKE_CURRENT_BINARY_DIR}
    LIBRARIES pp_ssc ssc_server_ros
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${common_INCLUDE_DIRS}
    ${semantic_map_manager_INCLUDE_DIRS}
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_library(pp_ssc
    src/ssc_planner/ssc_planner.cpp
    src/ssc_planner/ssc_map.cpp
    src/ssc_planner/map_adapter.cpp
    ${PROTO_SRCS}
)
target_link_libraries(pp_ssc PRIVATE
    pp_common
    pp_smm
    "${OpenMP_CXX_FLAGS}"
)

target_compile_options(pp_ssc PRIVATE "${OpenMP_CXX_FLAGS}")

add_library(ssc_server_ros
    src/ssc_planner/ssc_server_ros.cpp
    src/ssc_planner/ssc_visualizer.cpp
)
target_link_libraries(ssc_server_ros PRIVATE
    pp_ssc
    pp_smm_ros
    ${OpenMP_CXX_FLAGS}
)

#install the hearder files so that other packages can include.
#install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
 #  DESTINATION ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_INCLUDE_DESTINATION}/
 #  FILES_MATCHING PATTERN "*.h"
 #  PATTERN ".svn" EXCLUDE
#)
