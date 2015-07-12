#include "editor.hpp"

#include "terminal.hpp"
#include <cdk/cdk.h>

struct Editor::impl 
{
  CDKSCREEN* screen() {
    static auto screen_ = initCDKScreen(stdscr);  
    return screen_;
  }
  CDKENTRY* widget = nullptr;

};

Editor::~Editor() {
}

Editor::Editor(int y, int x, int w) : Editor(y, x, w, string()) {
}

Editor::Editor(int y, int x, int w, string l) 
  : p(std::make_unique<impl>()), x_(x), y_(y), width_(w), label_(l)
{
  p->widget = newCDKEntry (
      p->screen(),
      x_,
      y_,
      nullptr,
      const_cast<char*>(label_.c_str()), 
      0,
      ' ',
      vMIXED,
      width() - label_.size(),
      0,
      255,
      false,      // box
      false);
};

void Editor::v_refresh() {
  drawCDKEntry(p->widget, false);
}

#include "result.hpp"

Result Editor::show() {
  const char* result = activateCDKEntry(p->widget, nullptr);
  if(result == nullptr) {
    if(p->widget->exitType == vESCAPE_HIT) {
      return Result::Cancel;
    }
  }
  value_ = result;
  return Result::Ok;
}

auto Editor::v_rect() const -> Rect
{
  return Rect(x(), y(), x() + width(), y());
}
