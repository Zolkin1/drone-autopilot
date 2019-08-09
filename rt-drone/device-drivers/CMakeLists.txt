add_library(driver-lib
	src/MS5611.cpp
	src/I2Cdev.cpp
	src/Util.cpp
	src/RCOutput_Navio.cpp
	src/RCOutput_Navio2.cpp
	src/PWM.cpp
	src/RCInput_Navio.cpp
	src/RCInput_Navio2.cpp
	src/MPU9250.cpp)

target_include_directories(driver-lib PUBLIC
	inc)