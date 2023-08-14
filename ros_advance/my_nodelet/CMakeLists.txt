cmake_minimum_required(VERSION 2.8.3)
project(my_nodelet)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
        COMPONENTS
        roscpp
        std_msgs
        nodelet
)

include_directories(include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS include/${PROJECT_NAME}
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
    roscpp
    std_msgs
    nodelet
)

add_library(${PROJECT_NAME}
            src/my_nodelet.cpp
)


target_link_libraries(${PROJECT_NAME}
   ${catkin_LIBRARIES}
)

add_executable(${PROJECT_NAME}_node src/my_nodelet_loader.cpp)

target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  ${PROJECT_NAME}
)


install(DIRECTORY include/${PROJECT_NAME}
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)

install(DIRECTORY cfg
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/cfg)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
