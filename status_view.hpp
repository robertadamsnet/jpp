/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.
  
  See LICENSE.txt for licensing information.

*/
#ifndef status_view_hpp_2015_06_24_1559
#define status_view_hpp_2015_06_24_1559 

#include "terminal.hpp"
#include "view.hpp"
#include <string>
#include <functional>

class StatusView final : public virtual View {
public:
  StatusView();
  void set_content(std::string s) { internal_ = s; }
  void set_external(const std::string& s) { content_ref_ = s; }
  void set_internal() { content_ref_ = internal_; }
  const std::string& content() const { return content_ref_; }
  void clear();
  
  int row() const { return Terminal::rect().bottom(); }
private:
  std::reference_wrapper<const std::string> content_ref_;
  std::string internal_;
  Rect rect_;

  virtual auto v_rect() const -> Rect override {
    return rect_;
  }

  virtual void v_activate() override {
    v_refresh();
  }

  virtual void v_refresh() override {
    clear();
    auto view_rect = Terminal::rect();
    Terminal::locate(view_rect.left(), view_rect.bottom());
    int print_len = 
      content().size()  < view_rect.width() ? 
      content().size()  : view_rect.width();
    Terminal::write(content().c_str(), print_len);
  }
};

inline 
StatusView::StatusView() : content_ref_(internal_) {
}

inline
void StatusView::clear() 
{
  auto view_rect = Terminal::rect();
  Terminal::locate(view_rect.left(), view_rect.bottom());
  Terminal::write(std::string(view_rect.width(), ' '));
}
#endif//status_view_hpp_2015_06_24_1559
