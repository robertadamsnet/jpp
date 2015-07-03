/*  
    Copyright (c) 2015 by Robert T. Adams 
    All Rights Reserved.

    See LICENSE.txt for licensing information.

*/
#ifndef command_hpp_2015_0629_0523
#define command_hpp_2015_0629_0523 

#include "result.hpp"

class Command {
public:
  Result commit() { return v_commit(); }
  Result undo() { return v_undo(); }
private:
  virtual Result v_commit() = 0;
  virtual Result v_undo() = 0;
};

#endif//command_hpp_2015_0629_0523
