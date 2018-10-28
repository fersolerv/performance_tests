#include <iostream>
#include <ros/ros.h>
#include <sstream>
#include <std_msgs/String.h>
#include "performance_tests/SuperAwesome.h"


using namespace std;

int rate = 10;

int main(int argc, char **argv) {

    ros::init(argc, argv, "publisher_cpp");
    ros::NodeHandle pub;
    ros::Publisher publisher = pub.advertise<performance_tests::SuperAwesome>("chatter", 1000);

    ros::Rate loop_rate = ros::Rate(rate);

    int count = 0;
    while (ros::ok()){
        performance_tests::SuperAwesome msg;
        stringstream ss;
        ss << "Publishing" << count;
        msg.data = ss.str();
        publisher.publish(msg);
        //ROS_INFO("Sending: %d", msg.data.c_str() );

        ros::spinOnce();
        loop_rate.sleep();
        ++count;
    }

    return 0;
}

