/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#include <hex_cpp_utils/interfaces.h>

#include <iostream>

using hex_utils::HexImu;

int main(int argc, char** argv) {
  HexImu imu = HexImu();
  std::cout << imu << std::endl;

  // copy operator
  std::cout << "#### copy ####" << std::endl;
  HexImu imu_constructor(imu);
  HexImu imu_equal = imu;
  imu.acc_lin << 1.0, 2.0, 3.0;
  imu.vel_ang << 4.0, 5.0, 6.0;
  std::cout << "raw imu: " << imu << std::endl;
  std::cout << "constructor imu: " << imu_constructor << std::endl;
  std::cout << "equal imu: " << imu_equal << std::endl;

  return 0;
}
