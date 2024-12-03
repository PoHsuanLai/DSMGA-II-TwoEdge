cmake_minimum_required(VERSION 3.10)
project(DSMGA2)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add this where you link libraries
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    link_libraries(stdc++fs)
endif()

# Add pybind11
add_subdirectory(pybind11)

# Set compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wall -march=native")

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/core
    ${CMAKE_SOURCE_DIR}/src/functions
    ${CMAKE_SOURCE_DIR}/src/utils
)

# Define source files
set(COMMON_SOURCES
    src/core/chromosome.cpp
    src/core/dsmga2.cpp
    src/core/fastcounting.cpp
    src/core/global.cpp
    src/utils/mt19937ar.cpp
    src/utils/myrand.cpp
    src/functions/spin.cpp
    src/functions/nk-wa.cpp
    src/functions/sat.cpp
    src/functions/fitness_functions.cpp
)

# Create bin directory if it doesn't exist
file(MAKE_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Create executables
add_executable(DSMGA2 
    ${COMMON_SOURCES}
    src/core/main.cpp
)

add_executable(sweep
    ${COMMON_SOURCES}
    src/core/sweep.cpp
)

add_executable(genZobrist
    src/utils/genZobrist.cpp
)

# Python module
pybind11_add_module(dsmga2 
    src/python_binding/ga_wrapper.cpp
    ${COMMON_SOURCES}
    src/core/sweep.cpp
)

target_include_directories(dsmga2 PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/core
    ${CMAKE_SOURCE_DIR}/src/functions
    ${CMAKE_SOURCE_DIR}/src/utils
)

# Link math library
find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
    target_link_libraries(DSMGA2 PRIVATE ${MATH_LIBRARY})
    target_link_libraries(sweep PRIVATE ${MATH_LIBRARY})
    target_link_libraries(genZobrist PRIVATE ${MATH_LIBRARY})
endif()

# For genZobrist specifically, you might want to add:
if(APPLE)
    target_link_libraries(genZobrist PRIVATE "-framework CoreFoundation")
endif()