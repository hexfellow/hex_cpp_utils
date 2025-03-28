/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#include <hex_cpp_utils/interfaces.h>

#include <iostream>

using hex_utils::HexOdom;

int main() {
  HexOdom odom;
  std::cout << odom << std::endl;

  // copy operator
  std::cout << "#### copy ####" << std::endl;
  HexOdom odom_constructor(odom);
  HexOdom odom_equal = odom;
  odom.vel_ang << 1.0, 2.0, 3.0;
  std::cout << "raw odom: " << odom << std::endl;
  std::cout << "constructor odom: " << odom_constructor << std::endl;
  std::cout << "equal odom: " << odom_equal << std::endl;

  return 0;
}
