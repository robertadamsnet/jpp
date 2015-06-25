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
