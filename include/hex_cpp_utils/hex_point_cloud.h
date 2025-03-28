/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#ifndef HEX_CPP_UTILS_HEX_POINT_CLOUD_H_
#define HEX_CPP_UTILS_HEX_POINT_CLOUD_H_

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "hex_stamp.h"

namespace hex_utils {

template <typename PointT>
struct HexPointCloud {
  HexStamp stamp;
  typename pcl::PointCloud<PointT>::Ptr points;

  // constructor
  HexPointCloud() {
    this->stamp = HexStamp();
    this->points =
        typename pcl::PointCloud<PointT>::Ptr(new pcl::PointCloud<PointT>);
  }

  // copy operator
  // always deep copy
  HexPointCloud(const HexPointCloud& that) {
    this->stamp = that.stamp;
    this->points = typename pcl::PointCloud<PointT>::Ptr(
        new pcl::PointCloud<PointT>(*that.points));
  }
  HexPointCloud& operator=(const HexPointCloud& that) {
    if (this == &that) {
      return *this;
    }

    this->stamp = that.stamp;
    this->points = that.points;
    return *this;
  }

  // print operator
  friend std::ostream& operator<<(std::ostream& os,
                                  const HexPointCloud& cloud) {
    os << "stamp: " << cloud.stamp << std::endl;
    os << "point cloud size: " << cloud.points->size() << std::endl;
    return os;
  }
};

}  // namespace hex_utils

#endif  // HEX_CPP_UTILS_HEX_POINT_CLOUD_H_