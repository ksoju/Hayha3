set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake/")

project(HNet LANGUAGES C CXX)

find_package (Threads)
find_package(OpenCV)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc/)
include_directories(${OpenCV_INCLUDE_DIRS})

set(source_path "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB SOURCES "${source_path}/*.cpp")

add_library(HNetCV SHARED ${SOURCES})

target_link_libraries(HNetCV LINK_PUBLIC Happy ${OpenCV_LIBRARIES})

install(TARGETS HNetCV LIBRARY DESTINATION libs/ COMPONENT Runtime)