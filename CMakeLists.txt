cmake_minimum_required(VERSION 3.0.0)

project(filesystemTest)

set(CMAKE_CXX_STANDARD 20)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # using Clang
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # using GCC
    message("using GCC")
    message("Set compiler to g++-8 to support std::filesystem")
    set(CMAKE_C_COMPILER gcc-8)
    set(CMAKE_CXX_COMPILER g++-8)
    #    add_compile_options(-Wall -Wextra -Wpedantic -Wconversion) #[[-Wlifetime]]
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread ")
    # Link filesystem library
    link_libraries(stdc++fs)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
    # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # using Visual Studio C++
endif()

set(SOURCES main.cpp)

# setup file extensions for cross-compilation
if(WIN32)
    set(PLATFORM_EXT "cxx")
else()
    if(UNIX AND NOT APPLE)
        set(LINUX TRUE)
        set(PLATFORM_EXT "cc")
    else()
        set(PLATFORM_EXT "mm")
    endif()
endif()

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME})
