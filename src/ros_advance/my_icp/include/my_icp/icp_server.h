#include<queue>
#include<ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/registration/icp.h>

#include <sensor_msgs/PointCloud2.h>


typedef pcl::PointCloud<pcl::PointXYZI> PC;
typedef pcl::PointCloud<pcl::PointXYZI>::Ptr PC_POINTER;

class ICP_SERVER{
	public:
		ICP_SERVER();
		~ICP_SERVER();
		void cloud_cb(const sensor_msgs::PointCloud2::ConstPtr cloud);
	private:
		ros::Subscriber pc_sub_;
		ros::NodeHandle nh_;
		std::queue<PC_POINTER> queue_;
};