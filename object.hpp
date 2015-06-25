/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved. 
  See LICENSE.txt for licensing information.
*/
#ifndef object_hpp_2015_0624_1622
#define object_hpp_2015_0624_1622

#include <string>
#include <list>

class Object {
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
