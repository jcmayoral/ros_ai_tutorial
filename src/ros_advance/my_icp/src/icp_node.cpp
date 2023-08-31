#include <my_icp/icp_server.h>

int main(int argc, char ** argv){
	ros::init(argc, argv, "my_icp");
	ICP_SERVER server;
	ros::spin();
}