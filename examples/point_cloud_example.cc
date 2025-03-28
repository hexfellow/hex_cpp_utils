/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#include <hex_cpp_utils/interfaces.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include <iostream>

struct PointXYZRTLT {
  PCL_ADD_POINT4D
  float reflectivity;
  uint8_t tag = 0;
  uint8_t line = 0;
  double timestamp = 0;
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
} EIGEN_ALIGN16;
POINT_CLOUD_REGISTER_POINT_STRUCT(
    PointXYZRTLT,
    (float, x, x)(float, y, y)(float, z, z)(float, reflectivity, reflectivity)(
        uint8_t, tag, tag)(uint8_t, line, line)(double, timestamp, timestamp))

using hex_utils::HexPointCloud;

int main() {
  // XYZ
  std::cout << "#### XYZ ####" << std::endl;
  HexPointCloud<pcl::PointXYZ> cloud;
  std::cout << cloud << std::endl;

  // copy operator
  std::cout << "#### copy ####" << std::endl;
  HexPointCloud<pcl::PointXYZ> cloud_constructor(cloud);
  HexPointCloud<pcl::PointXYZ> cloud_equal = cloud;
  cloud.points->push_back(pcl::PointXYZ(1.0, 2.0, 3.0));
  std::cout << "raw cloud: " << cloud << std::endl;
  std::cout << "constructor cloud: " << cloud_constructor << std::endl;
  std::cout << "equal cloud: " << cloud_equal << std::endl;

  // XYZRTLT
  std::cout << "#### XYZRTLT ####" << std::endl;
  HexPointCloud<PointXYZRTLT> cloud_xyzrtlt;
  std::cout << cloud_xyzrtlt << std::endl;

  // copy operator
  std::cout << "#### copy ####" << std::endl;
  HexPointCloud<PointXYZRTLT> cloud_xyzrtlt_constructor(cloud_xyzrtlt);
  HexPointCloud<PointXYZRTLT> cloud_xyzrtlt_equal = cloud_xyzrtlt;
  PointXYZRTLT point;
  point.x = 1.0;
  point.y = 2.0;
  point.z = 3.0;
  point.reflectivity = 0.0;
  point.tag = 2;
  point.line = 1;
  point.timestamp = 0.5;
  cloud_xyzrtlt.points->push_back(point);
  std::cout << "raw cloud: " << cloud_xyzrtlt << std::endl;
  std::cout << "constructor cloud: " << cloud_xyzrtlt_constructor << std::endl;
  std::cout << "equal cloud: " << cloud_xyzrtlt_equal << std::endl;

  return 0;
}