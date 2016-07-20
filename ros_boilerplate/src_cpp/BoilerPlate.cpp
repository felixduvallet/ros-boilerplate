#include <ros/ros.h>
#include <std_msgs/Int32.h>

#include <ros_boilerplate/BoilerPlate.h>

BoilerPlate::BoilerPlate(ros::NodeHandle *nodeHandle)
  : nodeHandle_(nodeHandle) {
  counter_ = 0;
}

bool BoilerPlate::init() {
  //subscriber_ = ros::Subscriber()
  //publisher_ = nodeHandle_->advertise<std_msgs::Int32>("foo_cpp", 10);
  subscriber_ = nodeHandle_->subscribe("foo_cpp", 10, &BoilerPlate::MsgCB, this);
  return true;
}

void BoilerPlate::MsgCB(const std_msgs::Int32::ConstPtr &msg) {
  ROS_INFO("Got callback");
  ROS_INFO_STREAM("Heard: " << msg->data);
}

bool BoilerPlate::spinOnce() {
  ++counter_;

  std_msgs::Int32 msg;
  msg.data = counter_;

  //publisher_.publish(msg);
  return true;
}
