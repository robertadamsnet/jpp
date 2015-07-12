cmake_minimum_required(VERSION 2.8.12)

find_package(Boost 1.55 REQUIRED COMPONENTS serialization)

set(sources 
  terminal.cpp 
  object.cpp 
  user_interface.cpp
  document.cpp
  form_dialog.cpp
  editor.cpp
  controller.cpp
)

set(libs curses form cdk ${Boost_LIBRARIES})

add_executable(jpp main.cpp ${sources})

target_link_libraries(jpp ${libs})

include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

add_executable(filegen filegen.cpp ${sources} )
target_link_libraries(filegen ${libs})
