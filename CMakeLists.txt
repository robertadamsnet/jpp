cmake_minimum_required(VERSION 2.8.12)

add_executable(jpp 
  main.cpp 
  terminal.cpp 
  object.cpp 
  user_interface.cpp
  document.cpp
  form_dialog.cpp
  editor.cpp
  tree_view.cpp
  controller.cpp
)

target_link_libraries(jpp curses form cdk)
