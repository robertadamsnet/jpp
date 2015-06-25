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
#include "terminal.hpp"
#include <curses.h>
#include <stdexcept>

namespace {
  class NCInit final {
  public:
    NCInit() {
      if(initscr() == NULL) {
        throw std::runtime_error("NCInit::NCInit(): 'initscr()' fail.");
      }
    }
    ~NCInit() {
      static int death_count = 0;
      if(++death_count > 1) {
        throw std::runtime_error("NCInit destructor called more than once.");
      }
      endwin();
    }
  };
  int cache_count_ = 0;

  inline void cache_hold() {
    ++cache_count_;
  }

  inline void cache_release() {
    --cache_count_;
    refresh();
  }
}

class Terminal::Cache final {
public:
  Cache()  {
    cache_hold();
  }

  ~Cache() {
    cache_release();
  }
};

Terminal::Terminal() {
  static NCInit nc_init;
}

Terminal::~Terminal() {
}

const Terminal&& Terminal::no_echo() {
  Terminal t;
  noecho();
  return std::move(t);
}

#pragma push_macro("getch")
#undef getch
int Terminal::getch() {
  Terminal t;
#pragma pop_macro("getch")
  return getch();
#undef getch
}

#pragma push_macro("refresh")
#undef refresh
void Terminal::refresh() {
  Terminal t;
#pragma pop_macro("refresh")
  if(cache_count_)
    ::refresh();
#undef refresh
}

Rect Terminal::size() {
  Terminal t;
  int x, y;
  getmaxyx(stdscr, y, x);
  Rect r = { 0, 0, x - 1, y - 1};
  return r;
}


#pragma push_macro("move")
#undef move
void Terminal::move(int y, int x) {
  Terminal t;
#pragma pop_macro("move")
  ::move(y, x);
#undef move
}


void Terminal::locate(int x, int y) {
  Terminal::move(y, x);
}

void Terminal::write(const char* s, int n) {
  Terminal t;
  addnstr(s, n);
  refresh();
}

void Terminal::write(const std::string& s) {
  write(s.c_str(), s.size());
}
