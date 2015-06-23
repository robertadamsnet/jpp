#include "terminal.hpp"
#include <curses.h>
#include <stdexcept>

namespace {
  class NCInit {
  public:
    NCInit() {
      if(initscr() == NULL) {
        throw std::runtime_error("NCInit::NCInit(): 'initscr()' fail.");
      }
    }
    ~NCInit() {
      endwin();
    }
  };
}

Terminal::Terminal() {
  static NCInit nc_init;
}

Terminal::~Terminal() {
}

#pragma push getch
#undef getch
int Terminal::getch() {
#pragma pop
  return getch();
#undef getch
}
