cmake_minimum_required(VERSION 3.27)
project(toybot)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
Include(FetchContent)


# Compiler Flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")


# Catch2 for tests
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.4.0 # or a later release
)
FetchContent_MakeAvailable(Catch2)

# src and test dirs
set(TOYBOT_SRC_DIR "${CMAKE_SOURCE_DIR}/src" CACHE INTERNAL "Project source directory")
set(TOYBOT_INC_DIR "${CMAKE_SOURCE_DIR}/src" CACHE INTERNAL "Project include directory")

include_directories(${TOYBOT_INC_DIR})


add_subdirectory(test)
add_subdirectory(src)



