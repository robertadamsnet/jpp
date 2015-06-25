/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.
  
  See LICENSE.txt for licensing information.

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

