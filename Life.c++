//----------
// includes
//----------

#include "Life.h"
#include <iostream>
#include <vector>
#include <unordered_map>




//--------------
// AbstractCell
//--------------

AbstractCell::AbstractCell(){}
AbstractCell::AbstractCell(cell_t cellType, bool alive): _alive(alive), _cellType(cellType){}

AbstractCell::~AbstractCell(){}

bool AbstractCell::deadOrAlive(std::vector<bool> neighbors){return 0;}
bool AbstractCell::getAlive(){return _alive;}

//--------------
// Cell
//--------------






//------------
// ConwayCell
//------------

ConwayCell::ConwayCell(){}
ConwayCell::ConwayCell(bool alive): AbstractCell(CONWAY, alive){}
ConwayCell::~ConwayCell(){}

bool ConwayCell::deadOrAlive(std::vector<bool> neighbors){
    int neighborCount = 0;

    for(int i = 0; i < (int) neighbors.size(); ++i){
        if(neighbors[i]){
            ++neighborCount;
        }
        if(neighborCount > 3){
            break;
        }
    }

    if(DEBUGC)
    std::cout << "Neighbor Count: " << neighborCount << std::endl;

    if(_alive){
        if(DEBUGC)
        std::cout << " I am alive " << std::endl;
        if(neighborCount < 2 ||  neighborCount > 3){
            return false;
        }else{
            return true;
        }
    }else{
        if(DEBUGC)
        std::cout << " I am dead " << std::endl;

        if(neighborCount == 3){
            return true;
        }
    }

    return false;
}



// //-------------
// // FredkinCell
// //-------------

FredkinCell::FredkinCell(){}
FredkinCell::FredkinCell(bool alive): AbstractCell(FREDKIN, alive){}
FredkinCell::~FredkinCell(){}


bool FredkinCell::deadOrAlive(std::vector<bool> neighbors){




    return false;
}
