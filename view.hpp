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
#ifndef view_hpp_2015_06_24_14_02
#define view_hpp_2015_06_24_14_02 

class View {
public:
  void show() { return v_show(); }
private:
  virtual void v_show() = 0;
};

#endif//view_hpp_2015_06_24_14_02
