# drone-autopilot
This repo provides a custom autopilot designed to be run on the Navio2 and Raspberry Pi 3 hardware. This is built with the ROS architecture. On the drone there are two 9 axis IMU sensors, a GPS, a barometer, 4 ESCs, and 2 servos right now. The hardware is subject to change. See below for a wiring diagram.

# Cloning and Building the Repo
1. Download ROS
    1. This is developed using ROS 1 melodic, and the Navio will be running ROS 1 kinetic. The suggested download is ROS melodic. Follow the link [here](http://wiki.ros.org/ROS/Installation). The only supported development enviroment is Ubuntu.
2. Clone this repo
3. Download pigpio
    1. Although this wont be of any use on your local machine (only useful to the Navio), it will allow you to run ```catkin_make``` without getting any build errors.
4. ```cd``` into the ```GC_Drone``` folder and run ```catkin_make``` this should build the entire workspace and should not give errors
5. Before starting development, please create a new branch with the convention ```<first intial><last inital>-<branch name>```

# Motor Calibration
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
Then plug in the ESC (should emit a 1-2-3 beep) then it should emit another beep and that indicates it is done. But you may need to publish a "low" message first to show it where the low signal is.If there are issues, follow [this](https://forum.arduino.cc/index.php?topic=270309.0) link. After that, the esc should be ready to fly!

# Style and File Naming
We will be following the ROS C++ style guie found [here](http://wiki.ros.org/CppStyleGuide).

When creating a new branch, please use the convention: initials-description_of_branch. For example, when @Zolkin1 is working on the quadrotor control system the new branch would be: zo-quadrotor_controls

# System Wiring Diagram

# ROS Publish and Subscribe Messages
Right now, the nodes we have are:
* main_controller
* imu
* barometer
* estimator

A GPS node will be added. The sensors will publish on their respective topics. The estimator will recieve these messages at different rates then use a multirate kalman filter to fuse the data and filter out noise. The estimator will publish an estimate of the state to the controller.

An nput node (either teleoperated or autonomous input) will publish a desired state. The controller will then take that along with the estimated state and attempt to output proper duty cycles to the motors.


# Controls
Right now we are attempting to do full state feedback on the quadrotor drone. This involves taking inputs from the sensors and piping that through a kalman filter. The Kalaman Filter will give an optimal estimate of the states of the drone. There are 12 states (a derivation will be linked in a paper that has yet to be added to github, talk to @Zolkin1 for details right now). After we have an estimate of the 12 states then we are applying LQR (Linear Quadratic Regulator) control. This is a form of optimal control using modern control methods.

# Project Management
Current to-do's and issues are being tracked in GitHub through issues and/or the project tab.
