cmake_minimum_required(VERSION 2.8.12)

add_executable(jpp 
  main.cpp 
  terminal.cpp 
  object.cpp 
  user_interface.cpp
  action_view.cpp
  action_map.cpp
)
target_link_libraries(jpp ncurses)
