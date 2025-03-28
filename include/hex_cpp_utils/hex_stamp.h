/****************************************************************
 * Copyright 2025 Dong Zhaorui. All rights reserved.
 * Author : Dong Zhaorui 847235539@qq.com
 * Date   : 2025-03-28
 ****************************************************************/

#ifndef HEX_CPP_UTILS_HEX_STAMP_H
#define HEX_CPP_UTILS_HEX_STAMP_H

#include <cstdint>
#include <iostream>

namespace hex_utils {

struct HexStamp {
  uint32_t sec;
  uint32_t nsec;

  // constructor
  HexStamp() : sec(0), nsec(0) {}
  HexStamp(uint32_t sec, uint64_t nsec) : sec(sec), nsec(nsec) {}

  // copy operator
  // always deep copy
  HexStamp(const HexStamp& that) {
    this->sec = that.sec;
    this->nsec = that.nsec;
  }
  HexStamp& operator=(const HexStamp& that) {
    if (this == &that) {
      return *this;
    }

    this->sec = that.sec;
    this->nsec = that.nsec;
    return *this;
  }

  // compare operator
  bool operator<(const HexStamp& that) const {
    if (this->sec < that.sec) {
      return true;
    } else if ((this->sec == that.sec) && (this->nsec < that.nsec)) {
      return true;
    } else {
      return false;
    }
  }
  bool operator>(const HexStamp& that) const {
    if (this->sec > that.sec) {
      return true;
    } else if ((this->sec == that.sec) && (this->nsec > that.nsec)) {
      return true;
    } else {
      return false;
    }
  }
  bool operator==(const HexStamp& that) const {
    return (this->sec == that.sec) && (this->nsec == that.nsec);
  }
  bool operator!=(const HexStamp& that) const { return !(*this == that); }
  bool operator<=(const HexStamp& that) const { return !(*this > that); }
  bool operator>=(const HexStamp& that) const { return !(*this < that); }

  // plus operator
  HexStamp operator+(double delta) const {
    if ((this->sec + this->nsec * 1e-9 + delta) < 0) {
      throw "Negative time is not allowed!";
    }

    HexStamp result = HexStamp();
    int64_t delta_sec = static_cast<int64_t>(delta);
    int64_t delta_nsec = static_cast<int64_t>((delta - delta_sec) * 1000000000);
    if (this->nsec + delta_nsec >= 1000000000) {
      result.sec = static_cast<uint32_t>(static_cast<int64_t>(this->sec) +
                                         delta_sec + 1);
      result.nsec = static_cast<uint32_t>(static_cast<int64_t>(this->nsec) +
                                          delta_nsec - 1000000000);
    } else if (this->nsec + delta_nsec < 0) {
      result.sec = static_cast<uint32_t>(static_cast<int64_t>(this->sec) +
                                         delta_sec - 1);
      result.nsec = static_cast<uint32_t>(static_cast<int64_t>(this->nsec) +
                                          delta_nsec + 1000000000);
    } else {
      result.sec =
          static_cast<uint32_t>(static_cast<int64_t>(this->sec) + delta_sec);
      result.nsec =
          static_cast<uint32_t>(static_cast<int64_t>(this->nsec) + delta_nsec);
    }
    return result;
  }

  // minus operator
  double operator-(const HexStamp& that) const {
    int64_t diff_sec =
        static_cast<int64_t>(this->sec) - static_cast<int64_t>(that.sec);
    int64_t diff_nsec =
        static_cast<int64_t>(this->nsec) - static_cast<int64_t>(that.nsec);
    double result = static_cast<double>(diff_sec) + diff_nsec * 1e-9;
    return result;
  }
  HexStamp operator-(double delta) const { return *this + (-delta); }

  // print operator
  friend std::ostream& operator<<(std::ostream& os, const HexStamp& stamp) {
    os << stamp.sec << "s " << stamp.nsec << "ns";
    return os;
  }
};

}  // namespace hex_utils

#endif  // HEX_CPP_UTILS_HEX_STAMP_H
