cmake_minimum_required(VERSION 2.8)
project(forward_simulator)

set(CMAKE_VERBOSE_MAKEFILE "true")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11  -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")

find_package(catkin REQUIRED COMPONENTS
    roscpp
    visualization_msgs
    sensor_msgs)

find_package(common REQUIRED)
find_package(vehicle_model REQUIRED)
#if this catkin packge's header is used by other packages, use catkin_package to
#declare the include directories of this package.
catkin_package(
    INCLUDE_DIRS include ${vehicle_model_INCLUDE_DIRS}
    LIBRARIES ${vehicle_model_LIBRARIES}
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${common_INCLUDE_DIRS}
    ${vehicle_model_INCLUDE_DIRS}
)

add_library(planning_forward_simulator
    src/forward_simulator/multimodal_forward.cpp
    src/forward_simulator/onlane_forward_simulation.cpp
)

target_link_libraries(planning_forward_simulator
    planning_common
    planning_vehicle_model
)

#install the hearder files so that other packages can include.
#install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
 #  DESTINATION ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_INCLUDE_DESTINATION}/
 #  FILES_MATCHING PATTERN "*.h"
 #  PATTERN ".svn" EXCLUDE
#)