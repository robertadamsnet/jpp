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
#ifndef menu_hpp_2015_06_23_1547
#define menu_hpp_2015_06_23_1547 

#include <string>
#include <functional>
#include <map>

class Menu {
public:
  enum Result {
    Ok,           // menu item result OK; exit menu system
    Cancel        // menu item cancelled; return to last node
  };

  enum Item {
    Name,
    Action
  };

  Menu();
  Menu(std::string);

  typedef std::function<Result(void)> action_type;

  Menu& add(int key, action_type action);
  Menu& add(int key, const Menu& submenu);

  Result run();

private:
  typedef std::map<int, action_type> item_map_type;

  item_map_type items_;

  Menu* parent_;

};

#endif//menu_hpp_2015_06_23_1547
