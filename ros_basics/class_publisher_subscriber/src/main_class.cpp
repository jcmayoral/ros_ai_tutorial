#include <class_publisher_subscriber/main_class.h>

MainClass::MainClass(): nh_("~"){
	//subscribe (topicname, queue, callback)
	main_subscriber_ = nh_.subscribe("main_topic", 1, &MainClass::main_cb,this);
	output_publisher_ = nh_.advertise<std_msgs::String>("node_output", 1);
	ros::spin();
};

MainClass::~MainClass(){
}

void MainClass::main_cb(const std_msgs::String::ConstPtr msg){
	ROS_INFO_STREAM("Your message is " << msg-> data);
	std_msgs::String output_msg;
	output_msg.data = "hello ROS world";
	output_publisher_.publish(output_msg);
};