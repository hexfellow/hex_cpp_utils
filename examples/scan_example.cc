/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#include <hex_cpp_utils/interfaces.h>

#include <iostream>

using hex_utils::HexScan;

int main(int argc, char** argv) {
  HexScan scan = HexScan();
  std::cout << scan << std::endl;

  // copy operator
  std::cout << "#### copy ####" << std::endl;
  HexScan scan_constructor(scan);
  HexScan scan_equal = scan;
  scan.distances.push_back(1.0);
  scan.intensities.push_back(2.0);
  std::cout << "raw scan: " << scan << std::endl;
  std::cout << "constructor scan: " << scan_constructor << std::endl;
  std::cout << "equal scan: " << scan_equal << std::endl;

  return 0;
}
