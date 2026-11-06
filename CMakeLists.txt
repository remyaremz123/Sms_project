cmake_minimum_required(VERSION 3.16)
project(StudentManager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
include(FetchContent)

if(MSVC)
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.14.0
	GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(googletest)

add_executable(StudentApp
	src/main.cpp
	src/Student.cpp
	src/StudentEntry.cpp
	src/StudentManager.cpp
)

target_include_directories(StudentApp PRIVATE include)

enable_testing()

add_executable(StudentTests
	tests/StudentTests.cpp
	tests/StudentManagerTests.cpp
	tests/StudentEntryMockTests.cpp
	src/Student.cpp
	src/StudentEntry.cpp
	src/StudentManager.cpp
)

target_include_directories(StudentTests PRIVATE include)
target_link_libraries(StudentTests PRIVATE GTest::gmock GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(StudentTests)