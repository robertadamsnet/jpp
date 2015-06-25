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
#ifndef object_hpp_2015_0624_1622
#define object_hpp_2015_0624_1622 

#include <list>
#include <string>

class Object final {
public:
  Object() noexcept;
  Object(const Object&) noexcept;
  Object(Object&&) noexcept;

  Object& operator=(const Object&) noexcept;
  Object& operator=(Object&&) noexcept;
  const std::string& name() const;
  const std::string& type() const;

  const std::list<Object>& members() const;

private:
  std::list<Object> members_;

};


#endif//object_hpp_2015_0624_1622
