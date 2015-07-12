/*  
    Copyright (c) 2015 by Robert T. Adams 
    All Rights Reserved.

    See LICENSE.txt for licensing information.

*/

#include "serialize.hpp"
#include "viewer.hpp"
#include "terminal.hpp"
#include <iostream>
#include "cursor.hpp"

int main() {
  using namespace std;
  // load the demo file
  auto doc = Document::from_file("demo.jpp");

//  doc.to_file("demo2.jpp");

  Terminal::getch();
  // create the view
  Viewer view(doc);

  view.activate();

  return 0; 
}

