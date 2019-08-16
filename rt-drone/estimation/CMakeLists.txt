add_library(estimation-lib
	src/AHRS.cpp)

target_include_directories(estimation-lib PUBLIC
	inc
	../util/inc)

target_link_libraries(estimation-lib driver-lib)