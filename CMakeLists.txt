project(Ipp3)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(Ipp3_SRCS Ipp3.cpp main.cpp)
qt4_automoc(${Ipp3_SRCS})
add_executable(Ipp3 ${Ipp3_SRCS})
target_link_libraries(Ipp3 ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
install(TARGETS Ipp3 RUNTIME DESTINATION bin)
