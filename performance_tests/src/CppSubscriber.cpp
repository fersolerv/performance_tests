#include <iostream>
#include <ros/ros.h>
#include <sstream>
#include <std_msgs/String.h>
#include "performance_tests/SuperAwesome.h"

using namespace std;

double counts = 0;
double start_time;
double end_time;

void subscriberCallback (const performance_tests::SuperAwesome::ConstPtr& msg)
{
  counts = counts + 1;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber_cpp");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("chatter", 1, subscriberCallback);
  double start = ros::Time::now ().toSec ();
  double Tnow = ros::Time::now().toSec ();
  while (ros::ok ())
  {
    Tnow = ros::Time::now().toSec();
    if (Tnow - start >= 1.0)
    {
      double average_rate = counts / (Tnow - start);
      ROS_INFO ("Receiving rate: %f", average_rate);
      start = Tnow;
      counts = 0;
    }
    ros::spinOnce();
  }
  return 0;
}


