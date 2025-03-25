# 25.03.2025 11:14:25 Genrated by cbp2cmake V2.9.0 Finale X86 
project(cbp2cmake LANGUAGES C)
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set (CMAKE_INSTALL_PREFIX /usr )
add_definitions(-DHESTI_WAS_HERE)
add_executable(cbp2cmake tools.c cbp2cmake.c)
find_package(Threads REQUIRED)
target_link_libraries(cbp2cmake ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS cbp2cmake RUNTIME DESTINATION bin)
