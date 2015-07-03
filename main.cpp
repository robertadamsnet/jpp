/*  
    Copyright (c) 2015 by Robert T. Adams 
    All Rights Reserved.

    See LICENSE.txt for licensing information.

*/

#include "user_interface.hpp"
#include "controller.hpp"

int main() { 
  Controller control;
  UserInterface ui(control);
  ui.activate();
  return 0; 
}

