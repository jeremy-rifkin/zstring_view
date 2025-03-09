cmake_minimum_required(VERSION 3.14)

project(
  zstring_view
  LANGUAGES CXX
)

add_executable(example example.cpp)
target_include_directories(example PRIVATE ../include)
target_compile_features(example PRIVATE cxx_std_23)
