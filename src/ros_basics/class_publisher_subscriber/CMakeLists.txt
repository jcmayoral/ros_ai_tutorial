cmake_minimum_required(VERSION 2.8.3)
project(class_publisher_subscriber)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
        COMPONENTS
        roscpp
	std_msgs
)


include_directories(include
  ${catkin_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
    roscpp
    std_msgs
)

add_library(${PROJECT_NAME}
            src/main_class.cpp
)

add_executable(${PROJECT_NAME}_node src/executable.cpp)

target_link_libraries(${PROJECT_NAME}
   ${catkin_LIBRARIES}
)


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
