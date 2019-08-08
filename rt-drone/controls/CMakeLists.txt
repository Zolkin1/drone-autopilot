find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_library(controls-lib
	src/pid.cpp
	src/quadrotor_controller.cpp)

target_include_directories(controls-lib PUBLIC
	inc
	../util/inc)

target_link_libraries(controls-lib driver-lib Eigen3::Eigen)