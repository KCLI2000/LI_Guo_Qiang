/**
 * @file pilot.h
 * @brief define the task that we should do in mission 9
 * @author mafp
 * @email 767102280@qq.com
 * @version 1.0.0
 * @date 2019/10/19
 */
#include "pilot_node.h"

void Pilot::set_target(float x,float y, float z)
{
    //TODO 怎么将参数搞成缺省的，没输入就不
        pilot_target_x = x;
        pilot_target_y = y;
        pilot_target_z = z;
}
void Pilot::set_target(float x,float y)
{
    pilot_target_x = x;
    pilot_target_y = y;
}
void Pilot::set_target(float z)
{
    pilot_target_z = z;
}
void Pilot::control_update()
{
    uint8_t state = mission_state_pull();
    /*
        初始状态，不做操作
    */
    if(state == 0)
    {
        return;
    }
    else if(state == 1)
    {
        bool takeoff_result;
        takeoff_result = takeoff();
        if(takeoff_result)  
        {
            // 起飞成功后进入悬停状态
            update_mission_state(1);
        }
    }
    /*
        悬停状态
    */
    else if(state == 2)
    {
        return;
    }
    /*
        水平移动
    */
    else if(state == 3)
    {
        geometry_msgs::Vector3 local_position;
        float error_x,error_y;
        local_position =this->position_pull();
		error_x  = pilot_target_x - local_position.x;
		error_y  = pilot_target_y - local_position.y;
        this->setPosHori(error_x,error_y);
    }
    /*
        爬升
    */
    else if(state == 4)
    {
       this->setPosVert(this->pilot_target_z);
    }
    /*
        降落
    */
    else if(state == 5)
    {
        land();
        ROS_INFO("Pilot is landing");
		this->update_mission_state(0);
    }
}

