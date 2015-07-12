/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.
  
  See LICENSE.txt for licensing information.

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
  static Rect             rect();
  static void             move(int y, int x);
  static void             locate(int x, int y);
  static void             write(const char* cstr, int sz);
  static void             write(const std::string& str);
  static void             refresh();

  static void             attr_reverse();
  static void             attr_normal();
};


#endif//terminal_hpp_2015_06_23_1509
