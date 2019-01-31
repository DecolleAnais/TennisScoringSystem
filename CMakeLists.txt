cmake_minimum_required(VERSION 3.12)
project(TennisScoringSystem)

include_directories(include)
include_directories(3rdparty/gtest/include)
include_directories(3rdparty/gtest)
add_executable(TennisScoringSystemTest 
      ./src/TennisGameScoringSystem.cpp
      ./src/TennisGameAdvantageScoringSystem.cpp
      ./src/TennisGameTieBreakScoringSystem.cpp
      ./src/TennisSetScoringSystem.cpp
      ./src/TennisScoringSystem.cpp
      ./test/TennisGameScoringSystemTest_utest.cpp
      ./test/TennisSetScoringSystemTest_utest.cpp
      ./test/TennisScoringSystemTest_utest.cpp
      ./3rdparty/gtest/gtest-all.cc
)
target_link_libraries(TennisScoringSystemTest pthread stdc++)


add_executable(TennisMatchTest 
      ./src/TennisGameScoringSystem.cpp
      ./src/TennisGameAdvantageScoringSystem.cpp
      ./src/TennisGameTieBreakScoringSystem.cpp
      ./src/TennisSetScoringSystem.cpp
      ./src/TennisScoringSystem.cpp
      ./src/main.cpp
)
target_link_libraries(TennisMatchTest pthread stdc++)


