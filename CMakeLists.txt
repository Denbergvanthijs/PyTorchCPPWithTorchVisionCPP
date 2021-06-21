cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(ImportNetwork)

find_package(Torch REQUIRED)
find_package(TorchVision REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(ImportNetwork ImportNetwork.cpp)
target_link_libraries(ImportNetwork "${TORCH_LIBRARIES}" TorchVision::TorchVision)
set_property(TARGET ImportNetwork PROPERTY CXX_STANDARD 14)
