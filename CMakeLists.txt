cmake_minimum_required(VERSION 3.0.2)
project(hex_cpp_utils VERSION 0.0.1)

########################################################
# Options
########################################################
option(BUILD_EXAMPLES "Build example programs" ON)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

########################################################
# Add library target
########################################################
add_library(hex_cpp_utils INTERFACE)

# Set include directories
target_include_directories(hex_cpp_utils
    INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Add dependencies
find_package(Eigen3 REQUIRED)
find_package(PCL REQUIRED)
target_link_libraries(hex_cpp_utils INTERFACE 
    Eigen3::Eigen
    ${PCL_LIBRARIES}
)

########################################################
# Add examples
########################################################
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

########################################################
# Install library
########################################################
# Install headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

# Install library
install(TARGETS hex_cpp_utils
    EXPORT hex_cpp_utilsTargets
    INCLUDES DESTINATION include
)

# Install cmake config
install(EXPORT hex_cpp_utilsTargets
    FILE hex_cpp_utilsTargets.cmake
    NAMESPACE hex_cpp_utils::
    DESTINATION lib/cmake/hex_cpp_utils
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/hex_cpp_utilsConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/hex_cpp_utilsConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/hex_cpp_utilsConfig.cmake"
    INSTALL_DESTINATION lib/cmake/hex_cpp_utils
)
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/hex_cpp_utilsConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/hex_cpp_utilsConfigVersion.cmake"
    DESTINATION lib/cmake/hex_cpp_utils
)
