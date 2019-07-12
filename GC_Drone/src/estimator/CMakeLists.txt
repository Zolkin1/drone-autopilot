cmake_minimum_required(VERSION 2.8.3)
project(estimator)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  sensor_msgs
  std_msgs
  message_generation
  message_runtime
  genmsg
)

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   imu_data.msg
   quad_rotor_states.msg
   motor_commands.msg
   barometer_data.msg
   human_inputs.msg
)

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
 )

catkin_package(
#	CATKIN_DEPENDS message_runtime roscpp sensor_msgs std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  /include
  /inlcude/eigen
)

link_directories( /include /include/Eigen)
find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(estimator src/estimator.cpp src/filter.cpp)
target_link_libraries(estimator Eigen3::Eigen ${catkin_LIBRARIES})
