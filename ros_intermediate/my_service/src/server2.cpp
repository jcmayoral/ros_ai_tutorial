#include <ros/ros.h>
#include <my_service/service.h>


class Server{
    public:
    Server(): nh("~"){
        service = nh.advertiseService("test_service", &Server::execute_service, this);
    }

    bool execute_service(my_service::service::Request &req,
                    my_service::service::Response &resp)
    {
        resp.C = req.A + req.B;
        ROS_INFO_STREAM("RESULT "<< resp.C);
        return true;
    }

    private:
    ros::NodeHandle nh;
    ros::ServiceServer service;
};


int main(int argc, char** argv){
    ros::init(argc, argv, "my_service");
    Server server;
    ROS_INFO("Ready to call service.");
    ros::spin();
}