add_library(driver-lib
	src/MS5611.cpp
	src/I2Cdev.cpp)

target_include_directories(driver-lib PUBLIC
	inc)