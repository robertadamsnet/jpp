#include "user_interface.hpp"

UserInterface::UserInterface() {
  Terminal::no_echo();
}

void UserInterface::v_show() {
  action_view_.show();  
}
