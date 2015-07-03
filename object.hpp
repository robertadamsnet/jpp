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
typedef std::unique_ptr<Object> pointer_t;
typedef std::list<pointer_t> members_t;
typedef members_t::iterator iterator_t;

class Object {
public:

  auto name() const -> const string&;
  auto type() const -> const string&;

  typedef std::set<string> tags_t;
  auto tags() const -> const tags_t&;

  auto members() const -> const members_t&;

  void insert(const iterator_t& p, pointer_t&& obj);

private:
  Object();

  string name_;
  string type_;
  tags_t tags_;

  members_t members_;
};

inline
Object::Object() {
}

inline
auto Object::name() const -> const string&
{
  return name_;
}

inline
void Object::insert(const iterator_t& p, pointer_t&& obj) {
  members_.insert(p, std::move(obj));
}

#endif//object_hpp_2015_0624_1622
