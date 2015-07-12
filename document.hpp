#ifndef document_2015_0704_0749
#define document_2015_0704_0749 

#include "object.hpp"

enum class Result;

class Document : public Object {
public:
  typedef std::string string;

  Document();

  auto license()    const -> const string&;
  auto author()     const -> const string&;
  auto copyright()  const -> const string&;
  auto warranty()   const -> const string&;
 
  static auto from_file(const std::string& filespec) -> Document;

  auto to_file(const std::string& filespec) const -> Result;

  struct {
    string license;
    string author;
    string copyright;
    string warranty;
  } data;
};

#endif//document_2015_0704_0749
