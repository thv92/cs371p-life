//----------
// includes
//----------

#include "Life.h"
#include <iostream>
#include <vector>





//--------------
// AbstractCell
//--------------

AbstractCell::AbstractCell(){}
AbstractCell::AbstractCell(cell_t cellType, bool alive): _alive(alive), _cellType(cellType){}

AbstractCell::~AbstractCell(){}

bool AbstractCell::deadOrAlive(){return 0;}


// //--------------
// // Cell
// //--------------






// //------------
// // ConwayCell
// //------------

ConwayCell::ConwayCell(){}
ConwayCell::ConwayCell(bool alive): AbstractCell(CONWAY, alive){}
ConwayCell::~ConwayCell(){}




// //-------------
// // FredkinCell
// //-------------

FredkinCell::FredkinCell(){}
FredkinCell::FredkinCell(bool alive): AbstractCell(FREDKIN, alive){}
FredkinCell::~FredkinCell(){}



