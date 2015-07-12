#ifndef viewer_hpp_2015_0705_1525
#define viewer_hpp_2015_0705_1525 

#include "view.hpp"
#include "rect.hpp"
#include "terminal.hpp"
#include "cursor.hpp"
#include <sstream>

class Formatter 
{
public:
  typedef std::string string;
  typedef std::pair<string, std::reference_wrapper<const Object>> line_t;
  typedef std::list<line_t> lines_t; 
  auto get_lines(const Object& o) const -> lines_t 
    { return v_get_lines(o); }
private:
  virtual auto v_get_lines(const Object&) const -> lines_t = 0;
};

class BasicFormatter final : public Formatter
{
  auto v_get_lines(const Object& obj) const 
    -> lines_t override
  {
    return impl_get_lines(obj);
  }

  auto impl_get_lines(const Object& obj, int indent = 0) const 
    -> lines_t
  {
    lines_t lines;
    for(const Object& o : obj.members()) {
      std::stringstream ss;
      ss << string(indent, ' ') << o.name() << ":" << o.type(); 
      lines.push_back(std::make_pair(ss.str(), std::ref(o)));
      if(!o.members().empty()) 
      {
        auto member_lines = v_get_lines(o);
        lines.splice(lines.end(), std::move(impl_get_lines(o, indent + 1)));
      }
    }
    return lines;
  }
};

class Viewer : public View {
public:
  Viewer(const Object& o);
private:
  std::reference_wrapper<const Object> object_;
  std::reference_wrapper<const Object> cursor_ = *(object_.get().members().begin());
  Rect rect_;

  virtual auto v_rect() const -> Rect override;

  virtual void v_activate() override; 
  virtual void v_refresh() override;
};

inline
Viewer::Viewer(const Object& o) 
  : object_(o), rect_(Terminal::rect())
{
}

inline 
auto Viewer::v_rect() const -> Rect 
{
  return rect_;
}

inline
void Viewer::v_activate()
{
  while(true)
  {
    int ch = Terminal::getch();
    v_refresh();
  }
}

inline
void Viewer::v_refresh()
{
  BasicFormatter f;
  auto lines = f.get_lines(object_);
  int y = rect().top();
  for(auto& l : lines)
  {
    if(y >= rect().top() && y <= rect().bottom()) 
    {
      Terminal::move(y, rect().left());
      auto& o = l.second;
      if(&o.get() == &cursor_.get()) {
        Terminal::attr_reverse();
        Terminal::write(l.first);
        Terminal::attr_normal();
      } else {
        Terminal::attr_normal();
        Terminal::write(l.first);
      }
    }
    ++y;
  }

}

#endif//viewer_hpp_2015_0705_1525
