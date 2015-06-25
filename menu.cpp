/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful  ,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
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


