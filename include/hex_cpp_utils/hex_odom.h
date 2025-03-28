/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#ifndef HEX_CPP_UTILS_HEX_ODOM_H
#define HEX_CPP_UTILS_HEX_ODOM_H

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <iostream>

#include "hex_stamp.h"

namespace hex_utils {

struct HexOdom {
  HexStamp stamp;
  Eigen::Vector3d vel_lin;
  Eigen::Vector3d vel_ang;
  Eigen::Affine3d base_in_odom;

  // constructor
  HexOdom() {
    this->stamp = HexStamp();
    this->vel_lin = Eigen::Vector3d::Zero();
    this->vel_ang = Eigen::Vector3d::Zero();
    this->base_in_odom = Eigen::Affine3d::Identity();
  }

  // copy operator
  // always deep copy
  HexOdom(const HexOdom& that) {
    this->stamp = that.stamp;
    this->vel_lin = that.vel_lin;
    this->vel_ang = that.vel_ang;
    this->base_in_odom = that.base_in_odom;
  }
  HexOdom& operator=(const HexOdom& that) {
    if (this == &that) {
      return *this;
    }

    this->stamp = that.stamp;
    this->vel_lin = that.vel_lin;
    this->vel_ang = that.vel_ang;
    this->base_in_odom = that.base_in_odom;
    return *this;
  }

  // print operator
  friend std::ostream& operator<<(std::ostream& os, const HexOdom& odom) {
    os << "stamp: " << odom.stamp << std::endl;
    os << "vel_lin: " << odom.vel_lin << std::endl;
    os << "vel_ang: " << odom.vel_ang << std::endl;
    os << "base_in_odom: " << odom.base_in_odom.matrix() << std::endl;
    return os;
  }
};

}  // namespace hex_utils

#endif  // HEX_CPP_UTILS_HEX_ODOM_H
