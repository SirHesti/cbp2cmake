# 13.04.2024 17:23:46 Genrated by cbp2cmake V2.1.0 Finale X86 
project(cbp2cmake LANGUAGES C)
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
set (CMAKE_INSTALL_PREFIX /usr )
add_executable(cbp2cmake tools.c cbp2cmake.c)
install(TARGETS cbp2cmake RUNTIME DESTINATION bin)
