cmake_minimum_required(VERSION 2.8.3)
project(my_library)
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

include_directories(
  include
)

add_library(my_library SHARED src/my_class.cpp)
add_executable(my_library_executable src/my_class_executable.cpp)

target_link_libraries(my_library_executable my_library)

install(
    TARGETS ${PROJECT_NAME} 
    DESTINATION lib/${PROJECT_NAME}
)

file(GLOB HEADERS include/*.h)

install(
    FILES ${HEADERS} 
    DESTINATION include/${PROJECT_NAME}
)