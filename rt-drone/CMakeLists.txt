cmake_minimum_required(VERSION 2.6)
project(rt-drone)

add_subdirectory(device-drivers)
add_subdirectory(controls)

add_executable(main.out
	main.cpp
	modules/src/control_ops.cpp
	modules/src/estimator.cpp
	util/src/thread_helpers.cpp
	modules/src/communication.cpp)

target_include_directories(main.out PUBLIC
	modules/inc
	util/inc)

target_link_libraries(main.out
	driver-lib
	pthread
	controls-lib)