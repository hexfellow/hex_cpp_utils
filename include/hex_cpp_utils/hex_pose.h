/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#ifndef HEX_CPP_UTILS_HEX_POSE_H
#define HEX_CPP_UTILS_HEX_POSE_H

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <iostream>

#include "hex_stamp.h"

namespace hex_utils {

struct HexPose {
  HexStamp stamp;
  Eigen::Affine3d new_in_old;

  // constructor
  HexPose() {
    this->stamp = HexStamp();
    this->new_in_old = Eigen::Affine3d::Identity();
  }

  // copy operator
  // always deep copy
  HexPose(const HexPose& that) {
    this->stamp = that.stamp;
    this->new_in_old = that.new_in_old;
  }
  HexPose& operator=(const HexPose& that) {
    if (this == &that) {
      return *this;
    }
  }

  // print operator
  friend std::ostream& operator<<(std::ostream& os, const HexPose& pose) {
    os << "stamp: " << pose.stamp << std::endl;
    os << "new_in_old: " << pose.new_in_old.matrix() << std::endl;
    return os;
  }
};

}  // namespace hex_utils

#endif  // HEX_CPP_UTILS_HEX_POSE_H
