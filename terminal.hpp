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
