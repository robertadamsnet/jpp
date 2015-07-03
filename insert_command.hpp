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
  InsertCommand(Object& target, const iterator_t& insert_pos, 
      string name, string type);

private:
  Object& target_;
  const iterator_t& insert_pos_;
  Object item_;
  virtual auto v_commit() -> Result override;
  virtual auto v_undo() -> Result override;

};

inline
InsertCommand::InsertCommand(Object& t, const iterator_t& p,
    string name, string type)
  : target_(t), insert_pos_(p), item_(name, type)
{
  
}

inline
auto InsertCommand::v_commit() -> Result
{
  return Result::Ok; 
}

inline
auto InsertCommand::v_undo() -> Result
{
  return Result::Ok;
}

#endif//insert_comand_hpp_2015_0701_2020
