#include "document.hpp"

Document::Document() {
}

#include "result.hpp"
#include "serialize.hpp"
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <fstream>

auto Document::from_file(const std::string& filespec) -> Document
{
  try {
    Document doc;
    std::ifstream fstrm(filespec);
    boost::archive::xml_iarchive ar(fstrm);
    ar & BOOST_SERIALIZATION_NVP(doc);
    return doc;    
  } catch(...) {
    return Document();
  }
}

auto Document::to_file(const std::string& filespec) const -> Result 
{
  try {
    std::ofstream f(filespec);
    boost::archive::xml_oarchive ar(f);
    ar & BOOST_SERIALIZATION_NVP(*this);
    return Result::Ok;
  }
  catch(...) {
    return Result::Fail;
  }
}
