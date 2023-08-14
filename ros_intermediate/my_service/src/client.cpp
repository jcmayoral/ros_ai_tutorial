#include <ros/ros.h>
#include <my_service/service.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "my_service_client");

  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<my_service::service>("test_service");
  my_service::service srv;
  srv.request.A = atoll(argv[1]);
  srv.request.B = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.C);
  }
  else
  {
    ROS_ERROR("Failed to call service test_service");
    return 1;
  }

  return 0;
}