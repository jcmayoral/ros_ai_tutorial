#include <ros/ros.h>
#include <my_icp/service.h>


bool execute_service(my_icp::service::Request &req,
                    my_icp::service::Response &resp)
{
    resp.succeed = false;
    return resp.succeed;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "my_service");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("test_service", execute_service);
    ROS_INFO("Ready to call service.");
    ros::spin();
}