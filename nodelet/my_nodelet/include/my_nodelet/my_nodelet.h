#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <std_msgs/String.h>

namespace my_nodelet{
    class MyNodelet : public nodelet::Nodelet {
    private:
        virtual void onInit();
        ros::Subscriber sub_;
        ros::Publisher pub_;
        ros::NodeHandle nh_;
        ros::Timer timer_;

    public:
        MyNodelet();
        void msg_cb(const std_msgs::String::ConstPtr& str_msg);
        void timer_cb(ros::TimerEvent& event);
    };
}
