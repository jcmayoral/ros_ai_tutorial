#include <ros_wrapper/ros_wrapper.h>

ROSWrapper::ROSWrapper(): my_class_(){
    ROS_INFO("ROS Constructor");
}

ROSWrapper::~ROSWrapper(){
    ROS_INFO("ROS destructor");
}
