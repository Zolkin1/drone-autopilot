cmake_minimum_required(VERSION 2.8.3)
project(controls)

find_package(catkin REQUIRED COMPONENTS
  estimator
  roscpp
  sensor_msgs
  sensors
  std_msgs
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

link_directories( /include /Navio2/C++/Navio )

add_executable(controls2 src/motor_calibration.cpp)
target_link_libraries(controls2 ${catkin_LIBRARIES} my_lib)
