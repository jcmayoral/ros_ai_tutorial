#include <ros/ros.h>
#include <my_service/service.h>

bool execute_service(my_service::service::Request &req,
                    my_service::service::Response &resp)
{
    ROS_INFO_STREAM("RESULT "<< req.A + req.B);
    resp.C = req.A + req.B;
    return true;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "my_service");
    ros::NodeHandle n;
    ros::ServiceServer service = n.advertiseService("test_service", execute_service);
    ROS_INFO("Ready to call service.");
    ros::spin();
}