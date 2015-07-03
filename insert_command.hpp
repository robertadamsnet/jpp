/*  
    Copyright (c) 2015 by Robert T. Adams 
    All Rights Reserved.

    See LICENSE.txt for licensing information.

*/
#ifndef insert_comand_hpp_2015_0701_2020
#define insert_comand_hpp_2015_0701_2020 

#include "command.hpp"
#include "object.hpp"

class InsertCommand final : public Command {
public:
  InsertCommand(pointer_t& owner, const iterator_t& pos, pointer_t objptr);

private:
  pointer_t& owner_;
  const iterator_t& pos_;
  pointer_t objptr_;

  virtual auto v_commit() -> Result override;
  virtual auto v_undo() -> Result override;
  
};

InsertCommand::InsertCommand(pointer_t& o, const iterator_t& p, 
    pointer_t ptr) 
  : owner_(o), pos_(p), objptr_(std::move(ptr))
{
   
}

auto InsertCommand::v_commit() -> Result 
{
  owner_->insert(pos_, std::move(objptr_));  
  return Result::Fail;  
}

auto InsertCommand::v_undo() -> Result 
{
  return Result::Fail;
}

#endif//insert_comand_hpp_2015_0701_2020
