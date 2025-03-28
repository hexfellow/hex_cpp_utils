/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#ifndef HEX_CPP_UTILS_HEX_IMU_H
#define HEX_CPP_UTILS_HEX_IMU_H

#include <Eigen/Core>
#include <Eigen/Geometry>
#include <iostream>

#include "hex_stamp.h"

namespace hex_utils {

struct HexImu {
  HexStamp stamp;
  Eigen::Vector3d acc_lin;
  Eigen::Vector3d vel_ang;

  // constructor
  HexImu() {
    this->stamp = HexStamp();
    this->acc_lin = Eigen::Vector3d::Zero();
    this->vel_ang = Eigen::Vector3d::Zero();
  }

  // copy operator
  // always deep copy
  HexImu(const HexImu& that) {
    this->stamp = that.stamp;
    this->acc_lin = that.acc_lin;
    this->vel_ang = that.vel_ang;
  }
  HexImu& operator=(const HexImu& that) {
    if (this == &that) {
      return *this;
    }

    this->stamp = that.stamp;
    this->acc_lin = that.acc_lin;
    this->vel_ang = that.vel_ang;
    return *this;
  }

  // print operator
  friend std::ostream& operator<<(std::ostream& os, const HexImu& imu) {
    os << "stamp: " << imu.stamp << std::endl;
    os << "acc_lin: " << imu.acc_lin << std::endl;
    os << "vel_ang: " << imu.vel_ang << std::endl;
    return os;
  }
};

}  // namespace hex_utils

#endif  // HEX_CPP_UTILS_HEX_IMU_H
