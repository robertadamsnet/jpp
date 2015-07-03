/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.
  
  See LICENSE.txt for licensing agreement.

*/
#ifndef view_hpp_2015_06_24_14_02
#define view_hpp_2015_06_24_14_02 

class View {
public:
  void activate() { v_refresh(); v_activate(); }
  void refresh() { v_refresh(); }
private:
  virtual void v_activate() {} 
  virtual void v_refresh() = 0;
};

#endif//view_hpp_2015_06_24_14_02
