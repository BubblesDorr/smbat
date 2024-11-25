cmake_minimum_required(VERSION 2.8)
project(common)

set(CMAKE_VERBOSE_MAKEFILE "true")
set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-std=c++11  -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall")

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(catkin REQUIRED COMPONENTS
    roscpp
    visualization_msgs
    sensor_msgs
    tf
)

find_package(Protobuf REQUIRED)
set(THIRD_PARTY_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/thirdparty)
set(THIRD_PARTY_INCLUDE_DIRS  ${THIRD_PARTY_INCLUDE_DIRS} ${PROTOBUF_INCLUDE_DIR})
set(OOQP_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/thirdparty/ooqp/include/ooqp)
set(PROTOBUF_GENERATE_CPP_APPEND_PATH TRUE PARENT_SCOPE)

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
find_package(Glog REQUIRED)

find_package(OOQP REQUIRED)
if(NOT OOQP_FOUND)
    message(FATAL_ERROR "OOQP not found.")
endif()

#if this catkin packge's header is used by other packages, use catkin_package to
#declare the include directories of this package.
catkin_package(
    INCLUDE_DIRS include ${THIRD_PARTY_INCLUDE_DIRS} ${EIGEN3_INCLUDE_DIR} ${OOQP_INCLUDE_DIRS}
    LIBRARIES planning_common
    CATKIN_DEPENDS roscpp visualization_msgs sensor_msgs tf
)

set(THIRD_PARTY_LIBRARIES
    dw
    ${GLOG_LIBRARIES}
    ${PROTOBUF_LIBRARY}
)

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    ${THIRD_PARTY_INCLUDE_DIRS}
    ${OOQP_INCLUDE_DIRS}
)

add_library(planning_ooqp_itf
    src/common/solver/ooqp_interface.cpp
    src/common/solver/qp_solver.cpp
)
target_link_libraries(planning_ooqp_itf
    ${OOQP_LIBRARIES}
)
set(COMMON_SRC
    src/common/basics/colormap.cpp
    src/common/basics/semantics.cpp
    src/common/basics/shapes.cpp
    src/common/basics/tool_func.cpp
    src/common/math/calculations.cpp
    src/common/rss/rss_checker.cpp
    src/common/idm/intelligent_driver_model.cpp
    src/common/mobil/mobil_model.cpp
    src/common/mobil/mobil_behavior_prediction.cpp
    src/common/spline/lookup_table.cpp
    src/common/spline/spline_generator.cpp
    src/common/lane/lane.cpp
    src/common/lane/lane_generator.cpp
    src/common/primitive/frenet_primitive.cpp
    src/common/state/state_transformer.cpp
    src/common/state/free_state.cpp
    src/common/circle_arc/circle_arc.cpp
    src/common/circle_arc/circle_arc_branch.cpp
)

add_library(planning_common
    ${COMMON_SRC}
)
target_link_libraries(planning_common
    ${THIRD_PARTY_LIBRARIES}
    opencv_core
    opencv_highgui
    planning_ooqp_itf
)

#install the hearder files so that other packages can include.
#install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
 #  DESTINATION ${CATKIN_DEVEL_PREFIX}/${CATKIN_PACKAGE_INCLUDE_DESTINATION}/
 #  FILES_MATCHING PATTERN "*.h"
 #  PATTERN ".svn" EXCLUDE
#)