cmake_minimum_required(VERSION 3.5)
project(sm_atomic_openai)

set(CMAKE_BUILD_TYPE "Debug")

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(smacc2 REQUIRED)
find_package(ros_timer_client REQUIRED)
find_package(http_client REQUIRED)
find_package(Boost COMPONENTS thread REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(include
                    ${smacc2_INCLUDE_DIRS}
                    ${ros_timer_client_INCLUDE_DIRS}
                    ${http_client_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node
                src/sm_atomic_openai/sm_atomic_openai_node.cpp)

target_link_libraries(${PROJECT_NAME}_node
  ${smacc2_LIBRARIES}
  ${ros_timer_client_LIBRARIES}
  ${http_client_LIBRARIES}
  ${Boost_LIBRARIES}
  ${OpenCV_LIBRARIES}
  OpenSSL::SSL
  OpenSSL::Crypto
)

ament_target_dependencies(${PROJECT_NAME}_node smacc2)

install(
  DIRECTORY include/
  DESTINATION include
)

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}
)

install(TARGETS
        ${PROJECT_NAME}_node
        DESTINATION lib/${PROJECT_NAME})

ament_package()
