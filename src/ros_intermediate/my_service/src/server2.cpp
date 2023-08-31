#include <ros/ros.h>
#include <my_service/service.h>
#include <std_msgs/Float32.h>
//Modificar esta clase para subscribirse a un topico de un entero int
//Guardar el valor como modificador
//El server devuelva (A+B) * modificador


class Server{
    public:
    Server(): nh("/"), modificador{1.0}{
        sub_ = nh.subscribe("modificador", 10, &Server::sub_cb, this);
        service = nh.advertiseService("test_service",&Server::execute_service, this);
    }

    bool execute_service(my_service::service::Request &req,
                    my_service::service::Response &resp)
    {
        resp.C = (req.A + req.B) * modificador;
        ROS_INFO_STREAM("RESULT "<< resp.C);
        return true;
    }

    void sub_cb (const std_msgs::Float32::ConstPtr msg){
        ROS_INFO_STREAM(msg->data);
        modificador = msg->data;
    }

    float modificador;

    private:
    ros::NodeHandle nh;
    ros::ServiceServer service;
    ros::Subscriber sub_;
};


int main(int argc, char** argv){
    ros::init(argc, argv, "my_service");
    Server server;
    ROS_INFO("Ready to call service.");
    ros::spin();
    return 0;
}
