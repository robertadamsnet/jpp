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
#include "object.hpp"

Object::Object() noexcept 
{
}

Object::Object(const Object& other) noexcept
  : members_(other.members_)
{
}

Object::Object(Object&& other) noexcept
  : members_(std::move(other.members_))
{

}

Object& Object::operator=(const Object& other) noexcept
{
  members_ = other.members_;
  return *this;
}

Object& Object::operator=(Object&& other) noexcept {
  members_.operator=(std::move(members_));
  return *this;
}

