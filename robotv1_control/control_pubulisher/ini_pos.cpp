#include "ros/ros.h"
#include "std_msgs/Float64.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher_customized");
  ros::NodeHandle n;

  ros::Publisher hip_1_pub = n.advertise<std_msgs::Float64>("/robotv1/leftleg_hip_1_joint_controller/command", 100);

  ros::Rate loop_rate(50);

  int count = 0;

  while (ros::ok())
  {
    std_msgs::Float64 hip_1_pos;
    std_msgs::String hip_1_msg;
       
    hip_1_pos.data = 1.4;

    std::stringstream ss;
    ss << "I will success !!! this is the number hip_1_pos = " << hip_1_pos.data;
    hip_1_msg.data = ss.str();
    ROS_INFO("%s", hip_1_msg.data.c_str());
   
    hip_1_pub.publish(hip_1_pos);

    ros::spinOnce();

    loop_rate.sleep();
  }


  return 0;
}
