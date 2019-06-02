# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "estimator: 1 messages, 0 services")

set(MSG_I_FLAGS "-Iestimator:/home/zolkin/GC_Drone/src/estimator/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(estimator_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg" NAME_WE)
add_custom_target(_estimator_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "estimator" "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(estimator
  "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/estimator
)

### Generating Services

### Generating Module File
_generate_module_cpp(estimator
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/estimator
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(estimator_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(estimator_generate_messages estimator_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg" NAME_WE)
add_dependencies(estimator_generate_messages_cpp _estimator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(estimator_gencpp)
add_dependencies(estimator_gencpp estimator_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS estimator_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(estimator
  "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/estimator
)

### Generating Services

### Generating Module File
_generate_module_eus(estimator
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/estimator
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(estimator_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(estimator_generate_messages estimator_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg" NAME_WE)
add_dependencies(estimator_generate_messages_eus _estimator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(estimator_geneus)
add_dependencies(estimator_geneus estimator_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS estimator_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(estimator
  "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/estimator
)

### Generating Services

### Generating Module File
_generate_module_lisp(estimator
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/estimator
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(estimator_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(estimator_generate_messages estimator_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg" NAME_WE)
add_dependencies(estimator_generate_messages_lisp _estimator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(estimator_genlisp)
add_dependencies(estimator_genlisp estimator_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS estimator_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(estimator
  "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/estimator
)

### Generating Services

### Generating Module File
_generate_module_nodejs(estimator
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/estimator
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(estimator_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(estimator_generate_messages estimator_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg" NAME_WE)
add_dependencies(estimator_generate_messages_nodejs _estimator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(estimator_gennodejs)
add_dependencies(estimator_gennodejs estimator_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS estimator_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(estimator
  "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimator
)

### Generating Services

### Generating Module File
_generate_module_py(estimator
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimator
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(estimator_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(estimator_generate_messages estimator_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/zolkin/GC_Drone/src/estimator/msg/imu_data.msg" NAME_WE)
add_dependencies(estimator_generate_messages_py _estimator_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(estimator_genpy)
add_dependencies(estimator_genpy estimator_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS estimator_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/estimator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/estimator
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/estimator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/estimator
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/estimator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/estimator
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/estimator)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/estimator
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimator)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimator\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/estimator
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
