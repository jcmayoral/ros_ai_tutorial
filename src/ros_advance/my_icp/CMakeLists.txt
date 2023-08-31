cmake_minimum_required(VERSION 2.8.3)
project(my_icp)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
        COMPONENTS
        roscpp
        std_msgs
        message_generation
)

find_package(PCL REQUIRED)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${PCL_INCLUDE_DIRS}
)

add_service_files(
  FILES
  service.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

add_library(${PROJECT_NAME} src/icp_server.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES} ${PCL_LIBRARIES})

add_executable(${PROJECT_NAME}_server src/server.cpp)
target_link_libraries(${PROJECT_NAME}_server ${catkin_LIBRARIES} ${PCL_LIBRARIES})
add_dependencies(${PROJECT_NAME}_server ${PROJECT_NAME}_generate_messages_cpp )

add_executable(${PROJECT_NAME}_client src/client.cpp)
target_link_libraries(${PROJECT_NAME}_client ${catkin_LIBRARIES})
add_dependencies(${PROJECT_NAME}_client ${PROJECT_NAME}_generate_messages_cpp )


catkin_package(
  #INCLUDE_DIRS include/${PROJECT_NAME}
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS
    roscpp
    std_msgs
)

install(DIRECTORY cfg
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/cfg)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
