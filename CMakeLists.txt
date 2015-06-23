cmake_minimum_required(VERSION 2.8.12)

add_executable(jpp main.cpp terminal.cpp menu.cpp)
target_link_libraries(jpp ncurses)
