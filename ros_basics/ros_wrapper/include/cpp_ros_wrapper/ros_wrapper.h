#include <ros/ros.h>
#include <my_library/my_class.h>

class ROSWrapper{
    public:
        ROSWrapper();
        ~ROSWrapper();
    private:
        MyClass my_class_;
};