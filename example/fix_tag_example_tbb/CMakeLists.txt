# AMLALE: Hm?
cmake_minimum_required(VERSION 3.15...3.31)

project(
  FixTBBExample
  VERSION 1.0
  LANGUAGES CXX)

find_package(Boost REQUIRED timer)
find_package(TBB REQUIRED)

add_executable(FixTBBExample example.cpp)

target_include_directories(FixTBBExample PUBLIC ${BOOST_INCLUDE_DIRS})

set_property(TARGET FixTBBExample PROPERTY CXX_STANDARD 20)
target_include_directories(FixTBBExample PUBLIC ../../include/ocl)
target_link_libraries(FixTBBExample PRIVATE Boost::timer TBB::tbb)
target_link_libraries(FixTBBExample PUBLIC ocl_fix.a)
