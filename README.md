# **hex_cpp_utils**

## **Overview**

A C++ utility library for `HEXFELLOW` repositories.

### **License**

This project is licensed under the terms of the Apache License 2.0 - see the [LICENSE](LICENSE) file for details.

### **Maintainer**

[Dong Zhaorui](https://github.com/IBNBlank)

### **Supported Platform**

- [x] **x64**
- [ ] **Jetson Orin Nano**
- [x] **Jetson Orin NX**
- [ ] **Jetson AGX Orin**
- [ ] **Horizon RDK X5**

---

## **Public APIs**

- [HexStamp](hex_stamp.h)
- [HexOdom](hex_odom.h)
- [HexPointCloud](hex_point_cloud.h)
- [HexScan](hex_scan.h)
- [HexPose](hex_pose.h)
- [HexImu](hex_imu.h)

### **HexStamp**

- **Members**

| Members | Description |
| :-----: | :---------: |
|  `sec`  |   Seconds   |
| `nsec`  | Nanoseconds |

- **Methods**

|                                  Methods                                   |               Description                |
| :------------------------------------------------------------------------: | :--------------------------------------: |
|                                `HexStamp()`                                |           Default constructor            |
|                  `HexStamp(uint32_t sec, uint32_t nsec)`                   | Constructor with seconds and nanoseconds |
|                `HexStamp& operator=(const HexStamp& that)`                 |         Copy assignment operator         |
|                `bool operator<(const HexStamp& that) const`                |            Less than operator            |
|                `bool operator>(const HexStamp& that) const`                |          Greater than operator           |
|               `bool operator==(const HexStamp& that) const`                |              Equal operator              |
|                  `HexStamp operator+(double delta) const`                  |              Plus operator               |
|                  `HexStamp operator-(double delta) const`                  |              Minus operator              |
|               `double operator-(const HexStamp& that) const`               |              Minus operator              |
| `friend std::ostream& operator<<(std::ostream& os, const HexStamp& stamp)` |              Print operator              |

- **Usage**

You can refer to [stamp_example.cc](examples/stamp_example.cc) for more details.

### **HexOdom**

- **Members**

|    Members     |       Description       |
| :------------: | :---------------------: |
|    `stamp`     |        Timestamp        |
|   `vel_lin`    |     Linear velocity     |
|   `vel_ang`    |    Angular velocity     |
| `base_in_odom` | Base link in odom frame |

- **Methods**

|                                 Methods                                  |       Description        |
| :----------------------------------------------------------------------: | :----------------------: |
|                               `HexOdom()`                                |   Default constructor    |
|                      `HexOdom(const HexOdom& that)`                      |     Copy constructor     |
|                `HexOdom& operator=(const HexOdom& that)`                 | Copy assignment operator |
| `friend std::ostream& operator<<(std::ostream& os, const HexOdom& odom)` |      Print operator      |

- **Usage**

You can refer to [odom_example.cc](examples/odom_example.cc) for more details.

### **HexPointCloud**

- **Members**

| Members  | Description |
| :------: | :---------: |
| `stamp`  |  Timestamp  |
| `points` | Point cloud |

- **Methods**

|                                     Methods                                     |       Description        |
| :-----------------------------------------------------------------------------: | :----------------------: |
|                                `HexPointCloud()`                                |   Default constructor    |
|                   `HexPointCloud(const HexPointCloud& that)`                    |     Copy constructor     |
|              `HexPointCloud& operator=(const HexPointCloud& that)`              | Copy assignment operator |
| `friend std::ostream& operator<<(std::ostream& os, const HexPointCloud& cloud)` |      Print operator      |

- **Usage**

You can refer to [point_cloud_example.cc](examples/point_cloud_example.cc) for more details.

### **HexScan**

- **Members**

|    Members    | Description |
| :-----------: | :---------: |
|    `stamp`    |  Timestamp  |
|  `distances`  |  Distances  |
| `intensities` | Intensities |

- **Methods**

|                                 Methods                                  |       Description        |
| :----------------------------------------------------------------------: | :----------------------: |
|                               `HexScan()`                                |   Default constructor    |
|                      `HexScan(const HexScan& that)`                      |     Copy constructor     |
|                `HexScan& operator=(const HexScan& that)`                 | Copy assignment operator |
| `friend std::ostream& operator<<(std::ostream& os, const HexScan& scan)` |      Print operator      |

- **Usage**

You can refer to [scan_example.cc](examples/scan_example.cc) for more details.

### **HexPose**

- **Members**

|   Members    |      Description       |
| :----------: | :--------------------: |
|   `stamp`    |       Timestamp        |
| `new_in_old` | New frame in old frame |

- **Methods**

|                                 Methods                                  |       Description        |
| :----------------------------------------------------------------------: | :----------------------: |
|                               `HexPose()`                                |   Default constructor    |
|                      `HexPose(const HexPose& that)`                      |     Copy constructor     |
|                `HexPose& operator=(const HexPose& that)`                 | Copy assignment operator |
| `friend std::ostream& operator<<(std::ostream& os, const HexPose& pose)` |      Print operator      |

- **Usage**

You can refer to [pose_example.cc](examples/pose_example.cc) for more details.

### **HexImu**

- **Members**

|  Members  |     Description     |
| :-------: | :-----------------: |
|  `stamp`  |      Timestamp      |
| `acc_lin` | Linear acceleration |
| `vel_ang` |  Angular velocity   |

- **Methods**

|                                Methods                                 |       Description        |
| :--------------------------------------------------------------------: | :----------------------: |
|                               `HexImu()`                               |   Default constructor    |
|                      `HexImu(const HexImu& that)`                      |     Copy constructor     |
|                `HexImu& operator=(const HexImu& that)`                 | Copy assignment operator |
| `friend std::ostream& operator<<(std::ostream& os, const HexImu& imu)` |      Print operator      |

- **Usage**

You can refer to [imu_example.cc](examples/imu_example.cc) for more details.

---

## **Getting Started**

### **Dependencies**

- [Eigen3](https://eigen.tuxfamily.org/)
- [PCL](https://pointclouds.org/)

### **Installation**

```bash
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make 
sudo make install
```

### **Usage**

1. Include the library in your project:

    ```cpp
    #include <hex_cpp_utils/interfaces.h>
    ```

2. Add the following to your `CMakeLists.txt`:

    ```cmakelist
    find_package(hex_cpp_utils REQUIRED)
    target_link_libraries(your_target PRIVATE 
        hex_cpp_utils::hex_cpp_utils
    )
    ```

3. Uninstall the library:

    ```bash
    sudo make uninstall
    ```
