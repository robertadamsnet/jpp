#ifndef controller_hpp_2015_0627_2213
#define controller_hpp_2015_0627_2213 

#include "object.hpp"

#include "document.hpp"
#include "user_interface.hpp"
#include "command.hpp"
#include "history.hpp"

class Controller {
public:
  typedef std::string string;
  Controller();

private:
  Document doc_;
  UserInterface ui_;
  History history_;
};


inline
Controller::Controller() 
  : doc_(Document(*this)), ui_(UserInterface(*this))
{
}


#endif//controller_hpp_2015_0627_2213
