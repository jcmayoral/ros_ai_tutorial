#include <my_library/my_class.h>

int main (int argc, char** argv){
    std::cout << "running pointers executable" << std::endl;
    MyClass* class_pointer;// new MyClass();
    MyClass object;
    class_pointer = &object;
    class_pointer->function1();
    //delete class_pointer;
    return 0;
}