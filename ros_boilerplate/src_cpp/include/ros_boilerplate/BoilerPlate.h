#ifndef __ROS_BOILERPLATE_H__
#define __ROS_BOILERPLATE_H__

#include <std_msgs/Int32.h>

class BoilerPlate {
public:
  BoilerPlate(ros::NodeHandle *nodeHandle);

  bool init();

  bool spinOnce();

  void MsgCB(const std_msgs::Int32::ConstPtr &msg);
protected:
  ros::NodeHandle *nodeHandle_;
  ros::Publisher publisher_;

  ros::Subscriber subscriber_;

  int counter_;

};

#endif  // __ROS_BOILERPLATE_H__