#ifndef line_editor_hpp_2015_06_27_1550
#define line_editor_hpp_2015_06_27_1550 

#include "view.hpp"
#include <string>
#include <memory>

enum class Result;

class Editor final : public virtual View {
public:
  ~Editor();
  typedef std::string string;

  Editor(int y, int x, int width);
  Editor(int y, int x, int width, string label);

  const int& x() const { return x_; }
  const int& y() const { return y_; }
  const int& width() const { return width_; }

  const string& value() const { return value_; }

  Result show();
private:
  int x_;
  int y_;
  int width_;
  string value_;
  const string label_;

  struct impl;
  std::unique_ptr<impl> p;
  auto v_rect() const -> Rect override;
  void v_refresh() override;
};

#endif//line_editor_hpp_2015_06_27_1550
