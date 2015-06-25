/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful  ,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
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


