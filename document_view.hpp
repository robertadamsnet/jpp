#ifndef document_view_hpp_2015_0704_2243
#define document_view_hpp_2015_0704_2243 

#include "rect.hpp"
#include "view.hpp"
#include <map>

class Viewer final : public View {
public:
  Viewer(Document&);

  void set_rect(const Rect& r);
private:
  Rect rect_;
  Document& doc_;
  iterator_t selection_ = doc_.members().begin();
  int cursor_x_ = 0;
  int cursor_y_ = 0;
  
  typedef std::map<iterator_t, bool> expanded_set_t;
  expanded_set_t expanded_items_;

  virtual auto v_rect() const -> Rect override;
  virtual void v_refresh() override;
  virtual void v_activate() override;

  typedef std::vector<string> lines_t;
  auto create_buffer() const -> lines_t;
};

inline 
void Viewer::set_rect(const Rect& r) {
  rect_ = r;
}

#include "terminal.hpp"

inline
Viewer::Viewer(Document& d) 
 : rect_(Terminal::rect()), doc_(d) 
{
}

inline
auto Viewer::v_rect() const -> Rect
{
  return rect_;
}

#include <sstream>

inline
void Viewer::v_refresh()
{
  using namespace std;
  bool halt = false;
  int y = cursor_y_;
  iterator_t scan_ = selection_;
  while(y < rect_.height()) {
    ++y;
  }
}

inline
void Viewer::v_activate()
{
  v_refresh();
  Terminal::getch();
}

auto Viewer::create_buffer() const -> lines_t
{
  auto current_line = cursor_y_; 
  // start from the currently selected object and work our way backwards

}






#endif//document_view_hpp_2015_0704_2243
