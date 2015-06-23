#include "menu.hpp"
#include "terminal.hpp"

Menu& Menu::add(int key, action_type action) {
  using namespace std;
  items_.insert(make_pair(key, action));
  return *this;
}

Menu& Menu::add(int key, const Menu& submenu) {
  add(key, std::bind(&Menu::run, submenu));
  return *this;
}

Menu::Result Menu::run() {
  bool resume = false;
  while(true) {
    int keystroke = Terminal::getch();
    auto matched_item = items_.find(keystroke);
    // if 'ESC' was pressed, exit with 'cancel' result
    if(keystroke == '\x1b') {
      return Cancel;
    }
    // if the keystroke did not match an item, try again
    if(matched_item == items_.end()) {
      resume = true;
    } else {
      auto action = matched_item->second;
      return action();
    }
  };
}


