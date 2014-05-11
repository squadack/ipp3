cmake_minimum_required(VERSION 2.6)


project(Ipp3)
set(CMAKE_AUTOMOC ON)

find_package (Qt5 COMPONENTS Core Gui Widgets)

include_directories (${Qt5Widgets_INCLUDE_DIRS} ${Ipp3_SOURCE_DIR}/src)

set(QT_LIBRARIES
 Qt5::Widgets
)


set (EXECUTABLE_OUTPUT_PATH "${Ipp3_BINARY_DIR}/bin")
# set (LIBRARY_OUTPUT_PATH "${Ipp3_BINARY_DIR}/lib")
set (CMAKE_CXX_FLAGS "-Wall -std=c++11 -fPIE")
set (CMAKE_BUILD_TYPE Debug)
message (Current\ build\ type:\ ${CMAKE_BUILD_TYPE})


add_subdirectory(src)