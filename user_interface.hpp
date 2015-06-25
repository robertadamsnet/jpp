#ifndef user_interface_hpp_2015_06_24_2024
#define user_interface_hpp_2015_06_24_2024 

class StatusView;

#include "status_view.hpp"
#include "action_view.hpp"

class UserInterface final : public virtual View {
public:
  UserInterface();
  const StatusView& status();
private:
  StatusView status_view_;
  ActionView action_view_;
  void v_show() override; 
    
};


#endif//user_interface_hpp_2015_06_24_2024
