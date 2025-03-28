/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#ifndef HEX_CPP_UTILS_HEX_SCAN_H
#define HEX_CPP_UTILS_HEX_SCAN_H

#include <vector>

#include "hex_stamp.h"

namespace hex_utils {

struct HexScan {
  HexStamp stamp;
  std::vector<float> distances;
  std::vector<float> intensities;

  // constructor
  HexScan() {
    this->stamp = HexStamp();
    this->distances = std::vector<float>();
    this->intensities = std::vector<float>();
  }

  // copy operator
  // always deep copy
  HexScan(const HexScan& that) {
    this->stamp = that.stamp;
    this->distances = that.distances;
    this->intensities = that.intensities;
  }
  HexScan& operator=(const HexScan& that) {
    if (this == &that) {
      return *this;
    }

    this->stamp = that.stamp;
    this->distances = that.distances;
    this->intensities = that.intensities;
    return *this;
  }

  // print operator
  friend std::ostream& operator<<(std::ostream& os, const HexScan& scan) {
    os << "stamp: " << scan.stamp << std::endl;
    os << "distances size: " << scan.distances.size() << std::endl;
    os << "intensities size: " << scan.intensities.size() << std::endl;
    return os;
  }
};

}  // namespace hex_utils

#endif  // HEX_CPP_UTILS_HEX_SCAN_H
