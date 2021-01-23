/**
 * @file pilot.h
 * @brief main file
 * @author mafp
 * @email 767102280@qq.com
 * @version 1.0.0
 * @date 2019/10/19
 */
#include "pilot_node.h"
Pilot* p = nullptr;
int main(int argc, char** argv)
{
    ros::init(argc,argv,"pilot");
    ros::NodeHandle nh;
    ros::Rate loop(50);
    Pilot pilot;
    p = &pilot;
    pilot.init();
    //! dji sdk消息订阅
	ros::Subscriber attitudeSub = nh.subscribe("dji_sdk/attitude", 10, &dji_attitude_callback);
    ros::Subscriber gpsSub      = nh.subscribe("dji_sdk/gps_position", 10, &dji_gps_callback);
    ros::Subscriber flightStatusSub = nh.subscribe("dji_sdk/flight_status", 10, &dji_flight_status_callback);
    ros::Subscriber displayModeSub = nh.subscribe("dji_sdk/display_mode", 10, &dji_display_mode_callback);
    ros::Subscriber localPosition = nh.subscribe("dji_sdk/local_position", 10, &dji_local_position_callback);
    ros::Subscriber imuSub = nh.subscribe("dji_sdk/imu",10,&dji_imu_callback);
    ros::Subscriber heightSub = nh.subscribe("dji_sdk/height_above_takeoff",10,&dji_height_callback);
	ros::Publisher ctrl_pub = nh.advertise<pilot::pilot_ctrl_cmd>("pilot/pilot_ctrl_api",10);
    ros::Subscriber pilot_ctrl_cmd = nh.subscribe("pilot/pilot_ctrl_api",10,&pilot_ctrl_cmd_callback); 
    ros::Duration(10).sleep();
	pilot.obtain_control();
    while(ros::ok())
    {
		pilot.control_update();
        ros::spinOnce();
        loop.sleep();
    }
}
