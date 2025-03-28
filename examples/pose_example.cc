/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#include <hex_cpp_utils/interfaces.h>

#include <iostream>

using hex_utils::HexPose;

int main(int argc, char** argv) {
  HexPose pose = HexPose();
  std::cout << pose << std::endl;

  // copy operator
  std::cout << "#### copy ####" << std::endl;
  HexPose pose_constructor(pose);
  HexPose pose_equal = pose;
  pose.new_in_old.translation() << 3.0, 2.0, 1.0;
  std::cout << "raw pose: " << pose << std::endl;
  std::cout << "constructor pose: " << pose_constructor << std::endl;
  std::cout << "equal pose: " << pose_equal << std::endl;

  return 0;
}