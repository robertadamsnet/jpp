/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful  ,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#ifndef rect_hpp_201506240948
#define rect_hpp_201506240948 

template<class T>
class BasicRect final {
public:
  typedef T value_type;
  
  BasicRect() noexcept;
  BasicRect(int, int, int, int) noexcept;
  BasicRect(const BasicRect&) noexcept;
  BasicRect(BasicRect&&) noexcept;

  BasicRect& operator=(const BasicRect&) noexcept = default;
  BasicRect& operator=(BasicRect&&) noexcept = default;
  value_type top() const noexcept;
  value_type left() const noexcept;
  value_type bottom() const noexcept;
  value_type right() const noexcept;

  value_type width() const noexcept;
  value_type height() const noexcept;

private:
  value_type x1_;
  value_type y1_;
  value_type x2_;
  value_type y2_;
};

template<class T>
BasicRect<T>::BasicRect() noexcept : BasicRect(0, 0, 0, 0)
{
}

template<class T>
BasicRect<T>::BasicRect(int l, int t, int r, int b) noexcept 
  : x1_(l), y1_(t), x2_(r), y2_(b)
{
}

template<class T>
BasicRect<T>::BasicRect(const BasicRect& that) noexcept 
  : BasicRect(that.x1_, that.y1_, that.x2_, that.y2_)
{
}

template<class T>
auto BasicRect<T>::width() const noexcept -> value_type {
  return right() - left() + 1;
}

template<class T>
auto BasicRect<T>::height() const noexcept -> value_type {
  return bottom() - top() + 1;
}

template<class T>
auto BasicRect<T>::left() const noexcept -> value_type {
  return x1_;
}

template<class T>
auto BasicRect<T>::right() const noexcept -> value_type {
  return x2_;
}

template<class T>
auto BasicRect<T>::top() const noexcept -> value_type {
  return y1_;
}

template<class T>
auto BasicRect<T>::bottom() const noexcept -> value_type {
  return y2_;
}

typedef BasicRect<int> Rect;




#endif//rect_hpp_201506240948
