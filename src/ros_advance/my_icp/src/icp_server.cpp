#include <my_icp/icp_server.h>

ICP_SERVER::ICP_SERVER(): nh_("~"){
	ROS_INFO("ICP Server Constructor");	
	pc_sub_ = nh_.subscribe("/velodyne_points", 1, &ICP_SERVER::cloud_cb, this);
}

ICP_SERVER::~ICP_SERVER(){
	
}

void ICP_SERVER::cloud_cb(const sensor_msgs::PointCloud2::ConstPtr cloud_msg){

	PC_POINTER input_cloud(new PC);
	pcl::fromROSMsg(*cloud_msg, *input_cloud);

	queue_.push(input_cloud);
	ROS_INFO_STREAM(queue_.size());

	if (queue_.size() < 2){
		return;
	}

	PC_POINTER output_cloud(new PC);
	output_cloud = std::move(queue_.front());

	//REMOVE FIRST ELEMENT
	queue_.pop();

	pcl::IterativeClosestPoint<pcl::PointXYZI, pcl::PointXYZI> icp;
	icp.setMaximumIterations(100);
	icp.setInputSource(input_cloud);
	//icp.setInputCloud(input_cloud);
	icp.setInputTarget(output_cloud);

	icp.setMaximumIterations (500);
	icp.setTransformationEpsilon (1e-9);
	icp.setMaxCorrespondenceDistance (0.05);
	icp.setEuclideanFitnessEpsilon (1);
	icp.setRANSACOutlierRejectionThreshold (1.5);


	pcl::PointCloud<pcl::PointXYZI>::Ptr finalCloud(new pcl::PointCloud<pcl::PointXYZI>);
	icp.align(*finalCloud);

	if (icp.hasConverged()){
		std::cout << "ICP converged." << std::endl
	            << "The score is " << icp.getFitnessScore() << std::endl;
	    std::cout << "Transformation matrix:" << std::endl;
	    std::cout << icp.getFinalTransformation() << std::endl;
	}
	else {
		std::cout << "ICP did not converge." << std::endl;
	}
}