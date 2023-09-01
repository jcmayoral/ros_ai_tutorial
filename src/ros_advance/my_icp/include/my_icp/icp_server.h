#include<queue>
#include <mutex>
#include<ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <boost/thread/mutex.hpp>
#include <pcl/registration/icp.h>
#include <sensor_msgs/PointCloud2.h>
#include <tf/transform_broadcaster.h>
#include <pcl_conversions/pcl_conversions.h>

typedef pcl::PointCloud<pcl::PointXYZI> PC;
typedef pcl::PointCloud<pcl::PointXYZI>::Ptr PC_POINTER;

class ICP_SERVER{
	public:
		ICP_SERVER();
		~ICP_SERVER();
		void cloud_cb(const sensor_msgs::PointCloud2::ConstPtr cloud);
		void timer_callback(const ros::TimerEvent&);
		void broadcast_transform(tf::Vector3 v, tf::Quaternion q);
	private:
		tf::TransformBroadcaster broadcaster_;
		tf::Transform transform_;
		ros::Subscriber pc_sub_;
		ros::Timer timer_;
		ros::NodeHandle nh_;
		boost::mutex mtx_;
		std::queue<PC_POINTER> queue_;
};