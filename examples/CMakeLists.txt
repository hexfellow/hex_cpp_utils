# Add stamp example
add_executable(stamp_example stamp_example.cc)
target_link_libraries(stamp_example PRIVATE hex_cpp_utils)

# Add odom example
add_executable(odom_example odom_example.cc)
target_link_libraries(odom_example PRIVATE hex_cpp_utils)

# Add point cloud example
add_executable(point_cloud_example point_cloud_example.cc)
target_link_libraries(point_cloud_example PRIVATE hex_cpp_utils)

# Add scan example
add_executable(scan_example scan_example.cc)
target_link_libraries(scan_example PRIVATE hex_cpp_utils)
install(TARGETS scan_example RUNTIME DESTINATION bin)

# Add pose example
add_executable(pose_example pose_example.cc)
target_link_libraries(pose_example PRIVATE hex_cpp_utils)

# Add imu example
add_executable(imu_example imu_example.cc)
target_link_libraries(imu_example PRIVATE hex_cpp_utils)
