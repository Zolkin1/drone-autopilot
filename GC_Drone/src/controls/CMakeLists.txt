cmake_minimum_required(VERSION 2.8.3)
project(controls)

find_package(catkin REQUIRED COMPONENTS
  estimator
  roscpp
  sensor_msgs
  sensors
  std_msgs
)

generate_messages(
   DEPENDENCIES
  estimator
 )

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  /Navio2/C++/Navio
  /include
)

set(YOUR_LIB_SOURCES
    include/RCOutput_Navio2.cpp
    include/Util.cpp
    include/RCOutput_Navio.cpp
    include/PWM.cpp
    include/gpio.cpp
    include/PCA9685.cpp
    include/I2Cdev.cpp
    include/ADC_Navio.cpp
    include/ADC_Navio2.cpp
    include/ADS1115.cpp
    include/Led_Navio.cpp
    include/gpio.cpp
    include/Led_Navio2.cpp
    include/LSM9DS1.cpp
    include/MB85RC256.cpp
    include/MPU9250.cpp
    include/MS5611.cpp
    include/PCA9685.cpp
    include/RCInput_Navio.cpp
    include/RCInput_Navio2.cpp
    include/RGBled.cpp
    include/Ublox.cpp
    include/Util.cpp)

add_library(#${PROJECT_NAME}
  my_lib ${YOUR_LIB_SOURCES}
)

link_directories( /include /Navio2/C++/Navio /include/Eigen )
find_package (Eigen3 3.3 REQUIRED NO_MODULE)


add_executable(controls2 src/motor_calibration.cpp)
add_executable(mainController src/top_level_controller.cpp src/controller.cpp)# include/Eigen/Dense)

target_link_libraries (mainController Eigen3::Eigen ${catkin_LIBRARIES})

target_link_libraries(controls2 ${catkin_LIBRARIES} my_lib)
