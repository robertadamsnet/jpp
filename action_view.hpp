#ifndef action_view_hpp_20150624_2122
#define action_view_hpp_20150624_2122 

#include "view.hpp"
#include "action_map.hpp"

class ActionView : public virtual View {
public:
  ActionView();

private:
  void v_show() override;
 
  ActionMap map_;
};

#endif//action_view_hpp_20150624_2122
