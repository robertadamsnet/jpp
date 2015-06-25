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
#ifndef terminal_hpp_2015_06_23_1509
#define terminal_hpp_2015_06_23_1509 

#include "rect.hpp"

#include <string>

class Terminal final {
private:
  Terminal();
  ~Terminal();
public:
  class Cache;

  static Cache            start_cache();

  static int              getch();
  static const Terminal&& no_echo();
  static Rect             size();
  static void             move(int, int);
  static void             locate(int, int);
  static void             write(const char*, int);
  static void             write(const std::string&);
  static void             refresh();
};


#endif//terminal_hpp_2015_06_23_1509
