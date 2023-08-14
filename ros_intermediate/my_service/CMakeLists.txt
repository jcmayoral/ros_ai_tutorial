cmake_minimum_required(VERSION 2.8.3)
project(my_service)

add_compile_options(-std=c++11)

find_package(catkin REQUIRED
        COMPONENTS
        roscpp
        std_msgs
        message_generation
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_service_files(
  FILES
  service.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

add_executable(server src/server.cpp)
target_link_libraries(server ${catkin_LIBRARIES})
add_dependencies(server ${PROJECT_NAME}_generate_messages_cpp )

add_executable(client src/client.cpp)
target_link_libraries(client ${catkin_LIBRARIES})
add_dependencies(client ${PROJECT_NAME}_generate_messages_cpp )

add_executable(server2 src/server2.cpp)
target_link_libraries(server2 ${catkin_LIBRARIES})
add_dependencies(server2 ${PROJECT_NAME}_generate_messages_cpp )

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
