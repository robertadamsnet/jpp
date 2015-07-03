/*  
    Copyright (c) 2015 by Robert T. Adams 
    All Rights Reserved.

    See LICENSE.txt for licensing information.

*/
#ifndef command_hpp_2015_0629_0523
#define command_hpp_2015_0629_0523 

#include "result.hpp"
#include <memory>

class Command {
public:
  Result commit() { return v_commit(); }
  Result undo() { return v_undo(); }
private:
  virtual Result v_commit() = 0;
  virtual Result v_undo() = 0;
};

typedef std::unique_ptr<Command> command_ptr;

#endif//command_hpp_2015_0629_0523
