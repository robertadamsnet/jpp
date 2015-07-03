/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.
  
  See LICENSE.txt for licensing information.

*/
#ifndef user_interface_hpp_2015_06_24_2024
#define user_interface_hpp_2015_06_24_2024 

class StatusView;

#include "status_view.hpp"
#include "tree_view.hpp"

#include <map>
#include <vector>
#include <memory>
#include <stack>
#include <functional>


class Controller;

class UserInterface final : public virtual View {
public:
  UserInterface(Controller&);

  Controller& controller() const;
private:
  Controller& controller_;
  void v_refresh() override;  
  void v_activate() override;
};


#endif//user_interface_hpp_2015_06_24_2024
