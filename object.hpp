/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved. 
  See LICENSE.txt for licensing information.
*/
#ifndef object_hpp_2015_0624_1622
#define object_hpp_2015_0624_1622

#include <list>
#include <string>
#include <set>
#include <tuple>

enum Fields {
  Type,
  Tags,
  Members
};

class Object;

typedef std::string string;
//typedef std::unique_ptr<Object> object_ptr;
typedef std::list<Object> members_t;
typedef members_t::const_iterator iterator_t;

class Object {
public:
  Object();
  Object(string name, string type);

  auto name() const -> const string&;
  auto type() const -> const string&;

  typedef std::set<string> tags_t;
  auto tags() const -> const tags_t&;

  auto members() const -> const members_t&;

  void move(Object& other, const iterator_t& item, 
      const iterator_t insert_pos);

private:
  string name_;
  string type_;
  tags_t tags_;

  members_t members_;
};

inline
Object::Object() {
}

inline
Object::Object(string n, string t)
  : name_(n), type_(t) 
{
}

inline
auto Object::name() const -> const string&
{
  return name_;
}

inline
void Object::move(Object& other, const iterator_t& item, 
    const iterator_t insert_pos)
{
  members_.splice(insert_pos, other.members_, item);
}

inline
auto Object::members() const -> const members_t&
{
  return members_;
}


#endif//object_hpp_2015_0624_1622
