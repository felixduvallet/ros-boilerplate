#include <ros/ros.h>
#include <ros_boilerplate/BoilerPlate.h>

int main(int argc, char **argv) {
  ros::init(argc, argv, "boilerplate_cpp");
  ros::NodeHandle nodeHandle;

  BoilerPlate boilerPlate(&nodeHandle);
  if(!boilerPlate.init()) {
    ROS_ERROR("Error initializing node.");
    return -1;
  }

  // Allow the subscribers and publishers to connect.
  ros::Duration(0.5).sleep();

  ROS_INFO_STREAM("Node started");
  ros::Rate rate = ros::Rate(2.0);
  while(ros::ok()) {
    boilerPlate.spinOnce();

    rate.sleep();
  }

  ROS_INFO_STREAM("Node finished");
}
