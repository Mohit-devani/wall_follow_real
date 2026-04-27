# ROS 2 TurtleBot3 WASD Control 🎮

This package provides simple keyboard (WASD) control for a TurtleBot3 robot in Gazebo using ROS 2.

It allows manual driving like a game:
- W → move forward
- A → turn left
- D → turn right
- S → stop

---

## 🚀 Features

- Real-time keyboard control
- Works with Gazebo TurtleBot3 simulation
- Uses `/cmd_vel` topic
- Simple and lightweight node
- Beginner-friendly ROS 2 teleoperation

---

## 🛠️ Requirements

Make sure you have:

- ROS 2 installed (Jazzy)
- TurtleBot3 simulation
- Gazebo
- colcon build tools

Install TurtleBot3:

```bash id="req1"
sudo apt install ros-$ROS_DISTRO-turtlebot3-gazebo
