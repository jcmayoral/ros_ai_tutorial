#include <my_library/my_class.h>

int main (int argc, char** argv){
    std::cout << "running pointers executable" << std::endl;
    MyClass* class_object = new MyClass();
    return 0;
}