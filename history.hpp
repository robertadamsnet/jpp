/*  
    Copyright (c) 2015 by Robert T. Adams 
    All Rights Reserved.

    See LICENSE.txt for licensing information.

*/
#ifndef command_stack_hpp_2015_07_01
#define command_stack_hpp_2015_07_01 

class History {
public:
  auto commit(Command&&)  -> Result;
  auto redo()             -> Result;
  auto undo()             -> Result;
private:
  typedef std::list<std::unique_ptr<Command>> list;
  typedef list::iterator iterator;
  void insert(Command&&);
  list history_;
  iterator position_;
};


inline
auto History::commit(Command&& cmd) -> Result 
{
  auto result = cmd.commit();
  if(result == Result::Ok) {
    insert(std::move(cmd));
  }  
  return result;
}
#endif//command_stack_hpp_2015_07_01
