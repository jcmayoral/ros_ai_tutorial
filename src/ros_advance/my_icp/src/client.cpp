#include <ros/ros.h>
#include <my_icp/service.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "my_service_client");

  ros::NodeHandle n("/");
  ros::ServiceClient client = n.serviceClient<my_icp::service>("test_service");
  my_icp::service srv;

  if (client.call(srv))
  {
    ROS_INFO("Sum: %b", srv.response.succeed);
  }
  else
  {
    ROS_ERROR("Failed to call service test_service");
    return 1;
  }

  return 0;
}