cmake_minimum_required(VERSION 3.15)

project(r-type VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(cmake/CPM.cmake)

set(CPM_SOURCE_CACHE "${CMAKE_BINARY_DIR}/cpm_cache")


CPMAddPackage(
    NAME SFML
    GITHUB_REPOSITORY SFML/SFML
    GIT_TAG 2.6.x
    OPTIONS
        "SFML_BUILD_AUDIO OFF"
        "GIT_SHALLOW ON"
        "EXCLUDE_FROM_ALL ON"
        "SYSTEM ON"
)

CPMAddPackage(
  NAME asiocmake
  GIT_REPOSITORY "https://github.com/OlivierLDff/asio.cmake"
  GIT_TAG "main"
  ASIO_TAG "master"
)

CPMAddPackage(
    NAME yaml-cpp
    GITHUB_REPOSITORY jbeder/yaml-cpp
    GIT_TAG yaml-cpp-0.7.0
    OPTIONS
        "YAML_CPP_BUILD_TESTS OFF"
        "YAML_CPP_BUILD_TOOLS OFF"
        "YAML_CPP_INSTALL OFF"
)


option(BUILD_CLIENT "Build the R-Type client" ON)
option(BUILD_ECS "Build the R-Type ECS library" ON)
option(BUILD_SERVER "Build the R-Type server" ON)
option(BUILD_FLAPPY_BIRD "Build the Flappy bird game" ON)

if(BUILD_ECS)
    add_subdirectory(src/ecs)
endif()

if(BUILD_SERVER)
    add_subdirectory(src/server)
endif()

if(BUILD_CLIENT)
    add_subdirectory(src/client)
endif()

if(BUILD_FLAPPY_BIRD)
    add_subdirectory(src/flappy_bird)
endif()
