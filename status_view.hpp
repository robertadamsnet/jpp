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
private:
  std::reference_wrapper<const std::string> content_ref_;
  std::string internal_;
  virtual void v_show() override {
    auto view_rect = Terminal::size();
    Terminal::locate(view_rect.left(), view_rect.bottom());
    std::string s = content();
    auto print_len = 
      content().size() > view_rect.width() ? 
      view_rect.width() : content().size();

    Terminal::write(s.c_str(), s.size());
  }
};

inline 
StatusView::StatusView() : content_ref_(internal_) {
}

#endif//status_view_hpp_2015_06_24_1559
