#include "action_map.hpp"

const ActionMap::map_type& ActionMap::map() const
{
  return map_;
}

ActionMap& ActionMap::insert(key_type k, action_type a) {
  map_.insert(make_pair(k, a));
  return *this;
}

bool ActionMap::execute(key_type k)  const  
{
  auto found_pos = map_.find(k);
  if(found_pos == map_.end()) {
    return false;
  } else {
    auto action = found_pos->second;
    auto result = action();
    return true;
  }
}


