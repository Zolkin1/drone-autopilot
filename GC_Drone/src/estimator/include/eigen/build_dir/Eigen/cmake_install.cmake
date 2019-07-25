# Install script for directory: /home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE FILE FILES
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/Cholesky"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/CholmodSupport"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/Core"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/Dense"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/Eigen"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/Eigenvalues"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/Geometry"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/Householder"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/IterativeLinearSolvers"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/Jacobi"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/LU"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/MetisSupport"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/OrderingMethods"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/PaStiXSupport"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/PardisoSupport"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/QR"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/QtAlignedMalloc"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/SPQRSupport"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/SVD"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/Sparse"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/SparseCholesky"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/SparseCore"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/SparseLU"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/SparseQR"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/StdDeque"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/StdList"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/StdVector"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/SuperLUSupport"
    "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/UmfPackSupport"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen" TYPE DIRECTORY FILES "/home/zolkin/drone-autopilot/GC_Drone/src/controls/include/eigen/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

