/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.
  
  See LICENSE.txt for licensing agreement.

*/
#ifndef view_hpp_2015_06_24_14_02
#define view_hpp_2015_06_24_14_02 

#include "rect.hpp"

class View {
public:
  auto rect() const -> Rect { return v_rect(); }

  void activate() { v_refresh(); v_activate(); }
  void refresh() { v_refresh(); }
private:
  virtual auto v_rect() const -> Rect = 0;

  virtual void v_activate() {} 
  virtual void v_refresh() = 0;
};



#endif//view_hpp_2015_06_24_14_02
