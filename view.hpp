#ifndef view_hpp_2015_06_24_14_02
#define view_hpp_2015_06_24_14_02 

class View {
public:
  void show() { return v_show(); }
private:
  virtual void v_show() = 0;
};

#endif//view_hpp_2015_06_24_14_02
