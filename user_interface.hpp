/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.
  
  See LICENSE.txt for licensing information.

*/
#ifndef user_interface_hpp_2015_06_24_2024
#define user_interface_hpp_2015_06_24_2024 

class StatusView;

#include "status_view.hpp"

#include <map>
#include <memory>

class Action {
public:
  enum Result {
    Ok,
    Cancel,
    Back,
    ErrorReset
  };
  
  const std::string& name() const { return v_name(); }
  std::function<Result(void)> action() const { return v_action(); }
private:
  virtual const std::string& v_name() const = 0;
  virtual std::function<Result(void)> v_action() const = 0;
};

class ActionItem final : public virtual Action {
private:
  std::string name_;
  std::function<Result(void)> action_;
  const std::string& v_name() const override;
  std::function<Result(void)> v_action() const override;
};

inline
std::function<Action::Result(void)> ActionItem::v_action() const {
  return action_;
}

inline
const std::string& ActionItem::v_name() const {
  return name_;
}

typedef std::map<int, std::unique_ptr<Action>> ActionMap;

class ActionView final : public virtual View, public virtual Action {
public:
  ActionView(std::string, const ActionMap&);
private:
  std::string name_;
  std::function<Result(void)> action_;
  const ActionMap& map_;
  void v_show() override;
  const std::string& v_name() const override;
  std::function<Result(void)> v_action() const override; 
  Result do_action();
};

inline 
ActionView::ActionView(std::string n, const ActionMap& m) 
: map_(m), name_(n)
{
}


inline 
void ActionView::v_show() {
}

inline
ActionView::Result ActionView::do_action() {
  StatusView status;
  status.set_content(name());
  status.show();
  ActionMap::iterator item_pos;
  while(true) {
    int ch = Terminal::getch();
    ActionMap::const_iterator found_item = map_.find(ch);
    if(found_item != map_.end()) {
      auto fn = found_item->second;
      auto result = fn();
      switch(result) {
      case Ok:
        return Ok;
      case Cancel:
        break;
      case Back:
        return Cancel;
      case ErrorReset:
        return ErrorReset;
      }
    }
  }
}

inline
const std::string& ActionView::v_name() const {
  return name_;
};

inline
std::function<Action::Result(void)> ActionView::v_action() const {
  return action_;
}

class UserInterface final : public virtual View {
public:
  UserInterface();
  const StatusView& status();
private:
  StatusView status_view_;
  void v_show() override; 
    
};


#endif//user_interface_hpp_2015_06_24_2024
