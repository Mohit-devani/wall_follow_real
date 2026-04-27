cmake_minimum_required(VERSION 3.8)
project(wall_follow_real)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

# =========================
# Wall Follow Node
# =========================
add_executable(wall_follow src/wall_follow.cpp)

ament_target_dependencies(wall_follow
  rclcpp
  sensor_msgs
  geometry_msgs
)

# =========================
# Install targets
# =========================
install(TARGETS
  wall_follow
  DESTINATION lib/${PROJECT_NAME}
)

# =========================
# Testing (optional)
# =========================
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
