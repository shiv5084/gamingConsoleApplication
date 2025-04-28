cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(GamingConsoleApp VERSION 1.0)

find_package(GTest REQUIRED)
#find_package(GMock REQUIRED)

add_executable(BowlingGameTest 
../app/src/BowlingGame.cpp 
../app/src/FrameFactory.cpp 
BowlingGameTest.cpp 
FrameFactoryTest.cpp
test_main.cpp
)

target_include_directories(BowlingGameTest  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../app/include)

option(UNIT_TEST "Enable UNIT_TEST" ON)

if(UNIT_TEST)
    target_compile_definitions(BowlingGameTest  PRIVATE UNIT_TEST)
endif()

option(CODE_COVERAGE "Enable coverage flags" ON)

if(CODE_COVERAGE)
    message(STATUS "Building with coverage flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage -g")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fprofile-arcs -ftest-coverage -g")
    
    target_link_libraries(BowlingGameTest  gcov)  
endif()

# Link against GMock via GTest namespace when GMockConfig.cmake not available
target_link_libraries(BowlingGameTest  ${GTEST_LIBRARIES} GTest::gmock ${GMOCK_LIBRARIES} pthread)  

