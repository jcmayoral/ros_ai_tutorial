#include <my_nodelet/my_nodelet.h>
#include <pluginlib/class_list_macros.h>

using namespace my_nodelet;

MyNodelet::MyNodelet(){
    ROS_INFO("ROS Constructor");
}

void MyNodelet::onInit(){
    nh_ = getNodeHandle();
    //timer_ = nh_.createTimer(ros::Duration(1.0), 
    //    &MyNodelet::timer_cb, this);
    pub_ = nh_.advertise<std_msgs::String>("outcome",10);
    sub_ = nh_.subscribe("incoming", 10,
        &MyNodelet::msg_cb, this);
}

void MyNodelet::timer_cb(ros::TimerEvent& event){
    NODELET_INFO("Timer callback");
}

void MyNodelet::msg_cb(const std_msgs::String::ConstPtr& str_msg){
    pub_.publish(str_msg);
}

PLUGINLIB_EXPORT_CLASS(my_nodelet::MyNodelet, nodelet::Nodelet);