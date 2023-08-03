#include <ros/ros.h>
#include <std_msgs/String.h>


class MainClass{
	public:
		MainClass();
		~MainClass();
		void main_cb(const std_msgs::String::ConstPtr msg);
	private:
		ros::NodeHandle nh_;
		ros::Subscriber main_subscriber_;
		ros::Publisher output_publisher_;
};
