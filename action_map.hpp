#ifndef action_map_hpp_2015_06240840
#define action_map_hpp_2015_06240840 

#include <functional>
#include <map>

class ActionMap {
public:
  typedef int key_type;
  typedef std::function<bool(void)> action_type;
  typedef std::map<key_type, action_type>
    map_type;

  const map_type& map() const;

  ActionMap& insert(key_type, action_type);

  bool execute(key_type) const;

private:
  map_type map_;
};


#endif//action_map_hpp_2015_06240840
