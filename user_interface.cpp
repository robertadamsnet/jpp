/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.
  
  See LICENSE.txt for licensing information.

*/
#include "user_interface.hpp"
#include "scoped_call.hpp"
#include "editor.hpp"
#include "controller.hpp"

UserInterface::UserInterface(Controller& c) 
  : controller_(c) 
{
  Terminal::no_echo();
}

const StatusView& UserInterface::status() const {
  return status_view_;
}

void UserInterface::hard_coded_menu() {
  typedef std::vector<std::string> msg_stack_type;
  
  std::function<void(std::function<void(int)>)> get_input;
 
  msg_stack_type msg_stack;
  
  enum class Result {
    Ok,
    Cancel,
    Back
  };

  typedef std::function<void(int)> switch_fn_type;

  auto combined_message = [&]() { 
    std::string message;
    for(const auto& s : msg_stack) {
      message += "[" + s + "]";
    }
    return message;
  };

  auto push_status = [&](const std::string& msg) {
    msg_stack.push_back(msg);
    status_view_.set_content(combined_message());
    status_view_.refresh();
  };

  auto pop_status = [&]() {
    msg_stack.pop_back();
    status_view_.set_content(combined_message());
    status_view_.refresh();
  };

  auto action = [&](std::function<void(void)> action, std::string name) {
    push_status(name);
    action();
    pop_status();
  };

  auto submenu_action = [&](std::function<void(int)> action, 
      std::string name) 
  {
    push_status(name);
    get_input(action);
    pop_status();
  };

  switch_fn_type create_menu = [&](int key) {
    switch(key) {
    case 'c':
      action(std::bind(&UserInterface::create_class, this), "Class");
    }
  };

  switch_fn_type top_menu = [&](int key) 
  {
    switch(key) {
    case 'c':
      submenu_action(create_menu, "Create");
    }
  };

  get_input = [&](std::function<void(int)> key_processor) 
  {
    int key = Terminal::getch(); 
    key_processor(key);
  };
    
  while(true) {
    submenu_action(top_menu, ">");
  }
}


void UserInterface::create_class() {
  Object obj;
  std::string& name = obj.get<Object::Name>();

  int column = status().content().size();
  int row = status().row();
  int width = Terminal::rect().width() - column;
  Editor e(row, column, width, "Name: ");
  auto result = e.activate();  
}

void UserInterface::v_refresh() {
  hard_coded_menu();
}

Controller& UserInterface::controller() const
{
  return controller_;
}
