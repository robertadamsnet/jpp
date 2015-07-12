/*  
    Copyright (c) 2015 by Robert T. Adams 
    All Rights Reserved.

    See LICENSE.txt for licensing information.

*/

#include "object.hpp"
#include "document.hpp"
#include "serialize.hpp"
#include <fstream>
#include <iostream>
#include <string>

int main() {
  using namespace std;

  Document document;
  document.data.warranty = "</warranty>";
  members_t cache;

  Object o("Foo", "class");
  Object m1("bar", "int");
  Object a1("arg1", "int");
  Object a2("arg2", "string");
  Object m2("var1", "float");
  o.append(std::move(m2));
  m1.append(std::move(a1));
  m1.append(std::move(a2));
  o.append(std::move(m1));
  document.append(std::move(o));

  {
    ofstream ofs("demo.jpp");
    boost::archive::xml_oarchive oa(ofs);
    oa << BOOST_SERIALIZATION_NVP(document);
  }

  Document document2;
  {
    ifstream ifs("demo.jpp");
    boost::archive::xml_iarchive ia(ifs);
    ia >> BOOST_SERIALIZATION_NVP(document2);
  }

  if(document != document2) {
    cout << "ERROR: De-serialization failed." 
         << "  Object model after reload does not match." << endl;
  }
  return 0; 
}

