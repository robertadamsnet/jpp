/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.
  
  See LICENSE.txt for licensing information.

*/
#ifndef document_hpp_2015_0626_1019
#define document_hpp_2015_0626_1019 

#include "object.hpp"
enum class Result {
  Ok,
  Cancel,
  Error,
  Back,
  ErrDuplicate
};

class Controller;

class Document {
public:
  Document(Controller&);
  typedef std::string string;

  auto global() const -> const Object&;
  auto insert(const Object& parent, unsigned position) -> Result;
private:

  Object global_;
  Controller& control_;
};

#include "controller.hpp"

inline
Document::Document(Controller& c) : control_(c) {
  global_.get<Object::Name>() = "::";
}

inline
auto Document::global() const -> const Object&
{
  return global_;
}


#include "serialize_tuple.hpp"

namespace boost {
namespace serialization {

template<class Archive>
void serialize(Archive& ar, Document& doc, unsigned int version) {
  ar& doc.global();
}

}
}
#endif//document_hpp_2015_0626_1019
