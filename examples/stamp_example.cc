/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#include <hex_cpp_utils/interfaces.h>

#include <iostream>

using hex_utils::HexStamp;

int main(int argc, char** argv) {
  HexStamp stamp1 = HexStamp(1, 2);
  HexStamp stamp2 = HexStamp(2, 1);
  std::cout << "stamp1: " << stamp1 << std::endl;
  std::cout << "stamp2: " << stamp2 << std::endl;

  // copy
  std::cout << "#### copy ####" << std::endl;
  HexStamp stamp3 = stamp1;
  std::cout << "stamp3 = stamp1" << std::endl;
  std::cout << "stamp3: " << stamp3 << std::endl;

  // compare
  std::cout << "#### compare ####" << std::endl;
  if (stamp1 < stamp2) {
    std::cout << "stamp1 is less than stamp2" << std::endl;
  } else {
    std::cout << "stamp1 is greater than stamp2" << std::endl;
  }
  if (stamp1 == stamp3) {
    std::cout << "stamp1 is equal to stamp3" << std::endl;
  } else {
    std::cout << "stamp1 is not equal to stamp3" << std::endl;
  }

  // plus
  std::cout << "#### plus ####" << std::endl;
  HexStamp stamp4 = stamp1 + 1.0;
  std::cout << "stamp4 = stamp1 + 1.0" << std::endl;
  std::cout << "stamp4: " << stamp4 << std::endl;

  // minus
  std::cout << "#### minus ####" << std::endl;
  HexStamp stamp5 = stamp2 - 1.0;
  std::cout << "stamp5 = stamp2 - 1.0" << std::endl;
  std::cout << "stamp5: " << stamp5 << std::endl;
  std::cout << "stamp5 - stamp2: " << stamp5 - stamp2 << "s" << std::endl;

  return 0;
}