#ifndef form_dialog_hpp_2015_06_27_1145
#define form_dialog_hpp_2015_06_27_1145 

#include "view.hpp"

#include <tuple>
#include <string>
#include <functional>
#include <list>

class Field {
public:
  typedef std::string string;

  template<class bound_ref_type>
  Field(bound_ref_type& v) : bound_ref_(&v) {
    fn_set_from_string_ = [&](const string& str) {
      bound_ref_type& value = *static_cast<bound_ref_type*>(bound_ref_);
    };
  }

  void set(const string& str) {
    fn_set_from_string_(str);
  }


private:
  std::function<void(const string&)> fn_set_from_string_;

  void* bound_ref_;
  std::string as_string_;
};


template<class...TArgs>
class FormDialog final : public virtual View {
public:
  FormDialog(TArgs&...args) 
    : fields_(create_list(args...))
  {
  }

private:
  typedef std::list<Field> field_list;
  field_list fields_;

  template<class UArg>
  static void add_fields(field_list& fl, UArg& arg) {
    fl.push_back(Field(arg));
  }

  template<class UArg, class...UArgs>
  static void add_fields(field_list& fl, UArg& arg, UArgs&...args) {
    add_fields(fl, arg);
    add_fields(fl, std::forward<UArgs&>(args)...);
  }

  static field_list create_list(TArgs&...args) {
    field_list fl;
    add_fields(fl, std::forward<TArgs&>(args)...);
    return fl;
  }

  void v_show() override {
        
  }

  void v_refresh() override {
  }

};

#endif//form_dialog_hpp_2015_06_27_1145
