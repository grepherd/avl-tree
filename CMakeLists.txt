
cmake_minimum_required(VERSION 3.0)

# Set input directories
set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CATCH_INCLUDE_DIR})

# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

# Source files are manually defined for now
# main.cpp is added later
set ( SRCS 
	${SRC}/tree.cpp
)
		
set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})


# Create a main executable
add_executable(main ${SRC}/main.cpp ${SRCS})

# Create a test executable that uses test.cpp instead of main.cpp
# 	also define UNIT_TEST to enable tests
add_executable(tests ${SRC}/test.cpp ${SRCS}) 
set_target_properties(tests PROPERTIES COMPILE_DEFINITIONS UNIT_TEST)
target_link_libraries(tests Catch)
