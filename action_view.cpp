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
