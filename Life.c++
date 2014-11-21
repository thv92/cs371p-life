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
AbstractCell::AbstractCell(cell_t cellType, bool alive): _alive(alive), _stateToChange(_alive) , _cellType(cellType){}

AbstractCell::~AbstractCell(){}

bool AbstractCell::deadOrAlive(std::vector<bool> neighbors){return 0;}
bool AbstractCell::getAlive(){return _alive;}
void AbstractCell::printStatus(std::ostream& w){}
void AbstractCell::execute(){}
AbstractCell* AbstractCell::clone() {
    return NULL;
}


//------------
// ConwayCell
//------------


ConwayCell::ConwayCell(){}
ConwayCell::ConwayCell(bool alive): AbstractCell(CONWAY, alive){}
ConwayCell::~ConwayCell(){}

ConwayCell* ConwayCell::clone(){
    return new ConwayCell(*this);
}

 void ConwayCell::printStatus(std::ostream& w){
    if(_alive){
        w << "*";
    }else{
        w << ".";
    }
 }

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
            _stateToChange = false;
            return false;
        }else{
            return true;
        }
    }else{
        if(DEBUGC)
        std::cout << " I am dead " << std::endl;

        if(neighborCount == 3){
            _stateToChange = true;
            return true;
        }
    }

    return false;
}


void ConwayCell::execute(){
    if(_alive != _stateToChange){
        _alive = _stateToChange;
    }    
}



//-------------
// FredkinCell
//-------------

FredkinCell::FredkinCell(){}
FredkinCell::FredkinCell(bool alive): AbstractCell(FREDKIN, alive), _age(0){}
FredkinCell::~FredkinCell(){}
FredkinCell* FredkinCell::clone(){
    return new FredkinCell(*this);
}

void FredkinCell::printStatus(std::ostream& w){
    if(_alive){
        if(_age < 10){
            w << _age;
        }else if(_age > 9){
            w << "+";
        }
    }else{
        w << "-";
    }
 }

int FredkinCell::amITwoYears(){
    if(_age < 2){
        return -1;
    }else if(_age == 2){
        return 0;
    }else{
        return 1;
    }
}



bool FredkinCell::deadOrAlive(std::vector<bool> neighbors){
    int neighborCount = 0;

    for(int i = 0; i < (int) neighbors.size(); ++i){
        if(((i%2) == 0) && neighbors[i]){
            ++neighborCount;
        }
    }

    if(DEBUGF)
    std::cout << "Neighbor Count: " << neighborCount << std::endl;

    if(_alive){
        if(DEBUGF)
        std::cout << " I am alive " << std::endl;
        if(neighborCount == 0 ||  neighborCount == 2 || neighborCount == 4){
            _stateToChange = false;
            return false;
        }else{
            return true;
        }
    }else{
        if(DEBUGF)
        std::cout << " I am dead " << std::endl;

        if(neighborCount == 1 || neighborCount == 3){
            _stateToChange = true;
            return true;
        }
    }

    return false;
}

void FredkinCell::execute(){
    if(_alive != _stateToChange){
        _alive = _stateToChange;
    }else if(_alive && _stateToChange){
        ++_age;
    }     
}


//--------------
// Cell
//--------------

Cell::Cell(){}
Cell::Cell(bool alive){
    p = new FredkinCell(alive);
}

Cell::Cell(const Cell& other): p(other.p->clone()){}

Cell::~Cell(){delete p;}

Cell& Cell::operator=(const Cell& other){
    if(this == &other){
        return *this;
    }

    delete p;
    p = other.p->clone();
    return *this;
}

bool Cell::deadOrAlive(std::vector<bool> neighbors){
   return p->deadOrAlive(neighbors);
}

void Cell::execute(){
    p->execute();
    if(p->getAlive()){
        if(FredkinCell* f = dynamic_cast<FredkinCell*>(p) ){
            if(f->amITwoYears() == 0){
                delete p;
                p = new ConwayCell(true);
            }
        }
    }
}

bool Cell::getAlive(){
    return p->getAlive();
}

void Cell::printStatus(std::ostream& w){
    p->printStatus(w);
}



