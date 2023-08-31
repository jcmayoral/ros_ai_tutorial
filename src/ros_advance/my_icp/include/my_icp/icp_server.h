#include<ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/registration/icp.h>

#include <sensor_msgs/PointCloud2.h>

class ICP_SERVER{
	public:
		ICP_SERVER();
		~ICP_SERVER();
		void cloud_cb(const sensor_msgs::PointCloud2& cloud);
	private:
		ros::NodeHandle nh_;
};