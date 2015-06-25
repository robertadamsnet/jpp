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
#ifndef action_map_hpp_2015_06240840
#define action_map_hpp_2015_06240840 

#include <functional>
#include <map>

class ActionMap {
public:
  typedef int key_type;
  typedef std::function<bool(void)> action_type;
  typedef std::map<key_type, action_type>
    map_type;

  const map_type& map() const;

  ActionMap& insert(key_type, action_type);

  bool execute(key_type) const;

private:
  map_type map_;
};


#endif//action_map_hpp_2015_06240840
