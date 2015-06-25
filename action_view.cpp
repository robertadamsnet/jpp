#include "action_view.hpp"
#include "terminal.hpp"

#include <iostream>

namespace {
  using namespace std;

  bool create_action() {
    static ActionMap map.insert('c', create_action);
    
    bool success = false;
    while(success == false) {
      success = map.execute();
    } 
  }
}

ActionView::ActionView() {
  map_.insert('c', create_action);
  
}

void ActionView::v_show() {
  while(true) {
    int ch = Terminal::getch();
    map_.execute(ch);
  }
}
