/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved. 
  See LICENSE.txt for licensing information.
*/
#ifndef object_hpp_2015_0624_1622
#define object_hpp_2015_0624_1622

#include <set>
#include <list>
#include <string>
#include <bitset>

class Object final {
public:
  Object();
  Object(const Object&) = default;
  Object(Object&&) noexcept = default;
  ~Object() = default;

  enum Fields {
    Name,
    Type,
    Tags,
    Members
  };

  enum Bitset {
    Pointer,
    Reference,
    Const,
    Virtual,
    Static,
    Override,
    Noexcept,
    Default,
    Pure,
    FunctionPointer,
    Lambda,
    MAX_BITSET_COUNT
  };

  typedef std::bitset<MAX_BITSET_COUNT> bitset;
  typedef std::string string;
  typedef std::unique_ptr<Object> ObjPtr;
  typedef std::list<Object> member_list;
  typedef std::tuple<string, string, bitset, member_list> data_type;
  

  
private:
  data_type data_;

public:
  auto data() const -> const data_type& { return data_; }

  template<Fields field>
  auto get() const -> decltype(std::get<field>(data())) {
    return std::get<field>(data_);
  }

  template<Fields field>
  auto get() -> decltype(std::get<field>(data_)) {
    return std::get<field>(data_);
  }
  
  auto name() const -> const string&    { return get<Name>(); }
  void set_name(string n)               { get<Name>() = n; }
};

typedef Object::ObjPtr ObjPtr;

inline 
Object::Object() {
}

#endif//object_hpp_2015_0624_1622
