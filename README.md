# drone-autopilot
This repo provides a custom autopilot designed to be run on the Navio2 and Raspberry Pi 3 hardware.

The software on this drone is split into two different parts: the realtime process and the ROS process. The real time computer is running a version of RT Linux on the pi connected to the Navio2. The ROS system is running on a seperate computer connected to the navio over ethernet. The RT system handles all the hardware interactions, control systems and estimation. The ROS system handles path planning, computer vision and high level "inteligence."

Notes:
This repo should probably be broken into one repo for the real time stuff and another repo for the ROS side.

# Cloning and Building the Repo
1. Download ROS
    1. This is developed using ROS 1 melodic, and the Navio will be running ROS 1 kinetic. The suggested download is ROS melodic. Follow the link [here](http://wiki.ros.org/ROS/Installation). The only supported development enviroment is Ubuntu.
2. Clone this repo
3. Download pigpio
    1. Although this wont be of any use on your local machine (only useful to the Navio), it will allow you to run ```catkin_make``` without getting any build errors.
4. ```cd``` into the ```GC_Drone``` folder and run ```catkin_make``` this should build the entire workspace and should not give errors
5. Before starting development, please create a new branch with the convention ```<first intial><last inital>-<branch name>```

# Motor Calibration
First version is a c++ program that needs to be run on the Navio2 pi.
Cmake and make the rt folder. Plug in the motor to PWM port 0. Run calibration.out as root. The ESC should emit a 1-2-3 beep then it should emit another beep and that indicates it is done. If that doesn't work then enter "0" into the terminal. If there are issues, follow [this](https://forum.arduino.cc/index.php?topic=270309.0) link.

Second version uses the ROS implementation (deprecated)
You will need to use ``` tmux ``` to create mulitple windows to run each rosnode. In each tmux window, you will need to run ```source /drone-autopilot/drone-autpilot/GC_Drone/devel/setup.bash``` to source this ROS workspace.
On one window run:
```
roscore
```
On another window run the following command with root privilages. You can run ```rosrun``` with root privalges by logging in as root through ```sudo su``` 
```
rosrun controls controls2
``` 
On another window run: 
```
rostopic pub /changeOut std_msgs/String "high"
```
Then plug in the ESC (should emit a 1-2-3 beep) then it should emit another beep and that indicates it is done. But you may need to publish a "low" message first to show it where the low signal is. If there are issues, follow [this](https://forum.arduino.cc/index.php?topic=270309.0) link. After that, the esc should be ready to fly!

# Style and File Naming
We will be following the ROS C++ style guie found [here](http://wiki.ros.org/CppStyleGuide).

When creating a new branch, please use the convention: initials-description_of_branch. For example, when @Zolkin1 is working on the quadrotor control system the new branch would be: zo-quadrotor_controls

# System Wiring Diagram

# RT System Architecture
Each "module" is run as an individual thread. To pass information between threads we are using FIFOs (pipes). The pipes are just byte streams and everything is currently done through ``memcpy`` although that should change to some type of message type (with starts and ends - need to write this api). The main threads are:
* Controls - takes the current states and the desired states and runs the controls algorithms and talks to the ESCs.
* Estimation - Reads values from sensors and outputs the values as a state estimate. Also does all the sensor fusion.
* Communication - responsible for reading information from the RPI ethernet cable and reading the RC input. Should only publish the appropriate message depending on state status (teleop vs autonomous).

Right now everything runs at the same rate because the FIFOs are exactly that: first in, first out. So if the estimation thread runs 10x faster than the controls thread then the controls thread will lag behind. Inter thread communication should be re-written to support different thread rates.

# ROS Publish and Subscribe Messages
Todo: this section

# Controls
We are running a PID controller on each axis (thrust, roll, pitch, yaw). This is then transformed into the motor input space and applied to the motors.

# Project Management
Current to-do's and issues are being tracked in GitHub through issues and/or the project tab.
