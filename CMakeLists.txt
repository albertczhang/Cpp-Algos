cmake_minimum_required(VERSION 3.14)
project(MADS_Library)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_BUILD_TYPE Release)

add_executable(MADS_Library main.cpp)
target_link_libraries(MADS_Library lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(lib STATIC
        src/Complex.cpp
        src/Matrix.cpp
        src/Graph.cpp
        src/Polynomial.cpp)
#install(TARGETS MADS_Library DESTINATION lib)
#install(FILES Complex.h Matrix.h DESTINATION include)


