#ifndef controller_hpp_2015_0627_2213
#define controller_hpp_2015_0627_2213 

#include "object.hpp"

#include "document.hpp"
#include "user_interface.hpp"

class Controller {
public:
  Controller();


  auto insert_object(const Object& parent, unsigned int position) -> Result;

private:
  Document doc_;
  UserInterface ui_;
};


inline
Controller::Controller() 
  : doc_(Document(*this)), ui_(UserInterface(*this))
{
}

inline 
auto Controller::insert_object(const Object& p, unsigned int pos)
  -> Result
{
  doc_.insert(p, pos);
  return Result::Ok;
}

#endif//controller_hpp_2015_0627_2213
