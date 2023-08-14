cmake_minimum_required(VERSION 3.2.0)
project(ros_wrapper)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
        COMPONENTS
        roscpp
)

find_library(my_library REQUIRED PATHS /usr/local/)

include_directories(include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS include/${PROJECT_NAME}
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
    roscpp
)

add_library(${PROJECT_NAME}
            src/ros_wrapper.cpp
)

add_executable(${PROJECT_NAME}_node src/ros_wrapper_node.cpp)

target_link_libraries(${PROJECT_NAME}
   ${catkin_LIBRARIES}
   my_library
)


 target_link_libraries(${PROJECT_NAME}_node
   ${catkin_LIBRARIES}
   ${PROJECT_NAME}
   my_library
 )


install(DIRECTORY include/${PROJECT_NAME}
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)

install(DIRECTORY cfg
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/cfg)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
