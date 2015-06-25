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
#ifndef action_view_hpp_20150624_2122
#define action_view_hpp_20150624_2122 

#include "view.hpp"
#include "action_map.hpp"

class ActionView : public virtual View {
public:
  ActionView();

private:
  void v_show() override;
 
  ActionMap map_;
};

#endif//action_view_hpp_20150624_2122
