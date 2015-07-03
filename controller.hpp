#ifndef controller_hpp_2015_0627_2213
#define controller_hpp_2015_0627_2213 

#include "object.hpp"

#include "user_interface.hpp"
#include "command.hpp"
#include "history.hpp"

class Controller {
public:
  typedef std::string string;
  Controller();

private:
  UserInterface ui_;
  History history_;
};


inline
Controller::Controller() 
  : ui_(UserInterface(*this))
{
}


#endif//controller_hpp_2015_0627_2213
