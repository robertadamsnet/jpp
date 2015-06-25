/*  
  Copyright (c) 2015 by Robert T. Adams 
  All Rights Reserved. 
  See LICENSE.txt for licensing information.
*/
  enum cla 
    Ok,           // menu item result OK; exit menu system
    Cancel        // menu item cancelled; return to last node
  };

  enum Item {
    Name,
    Action
  };

  Menu();
  Menu(std::string);

  typedef std::function<Result(void)> action_type;

  Menu& add(int key, action_type action);
  Menu& add(int key, const Menu& submenu);

  Result run();

private:
  typedef std::map<int, action_type> item_map_type;

  item_map_type items_;

  Menu* parent_;

};

#endif//menu_hpp_2015_06_23_1547
