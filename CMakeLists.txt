cmake_minimum_required(VERSION 3.12)
project(TennisScoringSystem)

include_directories(include)
include_directories(3rdparty/gtest/include)
include_directories(3rdparty/gtest)
add_executable(TennisScoringSystemTest 
      ./src/TennisGameScoringSystem.cpp
      ./src/TennisScoringSystem.cpp
      ./test/TennisScoringSystemTest_utest.cpp
      ./3rdparty/gtest/gtest-all.cc
)
target_link_libraries(TennisScoringSystemTest pthread stdc++)


