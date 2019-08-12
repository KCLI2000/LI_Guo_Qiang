#include <ros/ros.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include "jetsonGPIO.h"

void reqCallback (const std_msgs::Int32::ConstPtr& msg);

int main(int argc, char** argv)
{
		ros::init(argc, argv, "heal");
		ros::NodeHandle nh;
		ros::Rate looprate(10);

		jetsonTX2GPIONumber RaserControlPin = gpio388;
		gpioExport(RaserControlPin);
		gpioSetDirection(RaserControlPin, outputPin);

		ros::Subscriber heal = nh.subscribe<std_msgs::Int32>("heal/open_heal", 10, reqCallback);

		ros::spinOnce();

		return 0;
}

void reqCallback(const std_msgs::Int32::ConstPtr& msg)
{		
		if(msg->data)
		{
				gpioSetValue(RaserControlPin, on);
				ROS_INFO("HEALED");
		}

		gpioSetValue(RaserControlPin, off);
}



