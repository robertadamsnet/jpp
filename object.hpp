#ifndef object_hpp_2015_0624_1622
#define object_hpp_2015_0624_1622 

#include <list>
#include <string>

class Object final {
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
