cmake_minimum_required(VERSION 3.16)
project(snake)

set(CMAKE_CXX_STANDARD 20)
set(CXX /usr/bin/clang++)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# nvim clang lsp uses this to get the include paths and stuff.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(snake)

if(NOT CMAKE_BUILD_TYPE)
	set(default_build_type "Debug")
	message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
	set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
	"Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "cmake_test Build Type: ${CMAKE_BUILD_TYPE}")

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
    raylib
    GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
    GIT_TAG "master"
    GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

target_link_libraries(snake PRIVATE raylib)

# Setting ASSETS_PATH
target_compile_definitions(snake PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/") # Set the asset path macro to the absolute path on the dev machine
#target_compile_definitions(snake PUBLIC ASSETS_PATH="./assets") # Set the asset path macro in release mode to a relative path that assumes the assets folder is in the same directory as the game executable

# Set the version for cmake_test
set(cmake_test_Version_Major 0)
set(cmake_test_Version_Minor 1)
set(cmake_test_Version_Patch 0)
set(cmake_test_Version_Status "-dev")
set(PROJECT_VERSION
	"${cmake_test_Version_Major}.${cmake_test_Version_Minor}.${cmake_test_Version_Patch}${cmake_test_Version_Status}"
)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cc")
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/include/")

target_sources(snake PRIVATE ${SOURCES})
target_include_directories(snake PRIVATE ${PROJECT_INCLUDE})

message(STATUS "snake version: ${PROJECT_VERSION}")
