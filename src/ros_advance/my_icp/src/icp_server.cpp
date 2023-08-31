#include <my_icp/icp_server.h>

ICP_SERVER::ICP_SERVER(){

}


ICP_SERVER::~ICP_SERVER(){
	
}

void ICP_SERVER::cloud_cb(const sensor_msgs::PointCloud2& cloud_msg){

	pcl::PointCloud<pcl::PointXYZ>::Ptr input_cloud;
	pcl::fromROSMsg(cloud_msg, *input_cloud);

	pcl::PointCloud<pcl::PointXYZ>::Ptr output_cloud;
	pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;

	icp.setMaximumIterations(100);
	icp.setInputSource(input_cloud);

}