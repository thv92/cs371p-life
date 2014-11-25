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
bool AbstractCell::diag(){return false;}
bool AbstractCell::deadOrAlive(int neighbors){return 0;}
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
ConwayCell::ConwayCell(char alive): AbstractCell(CONWAY, alive == '*'){
}
ConwayCell::~ConwayCell(){}
bool ConwayCell::diag(){return true;}
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

bool ConwayCell::deadOrAlive(int neighbors){
    if(_alive){
        if(neighbors < 2 ||  neighbors > 3){
            _stateToChange = false;
            return false;
        }else{
            return true;
        }
    }else{
        if(neighbors == 3){
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
FredkinCell::FredkinCell(char alive): AbstractCell(FREDKIN, ((alive >= '0') && (alive <= '9')) || (alive == '+')), _age(0){}
FredkinCell::~FredkinCell(){}
FredkinCell* FredkinCell::clone(){
    return new FredkinCell(*this);
}

bool FredkinCell::diag(){return false;}

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



bool FredkinCell::deadOrAlive(int neighbors){
    if(_alive){
        if(neighbors == 0 ||  neighbors == 2 || neighbors == 4){
            _stateToChange = false;
            return false;
        }else{
            return true;
        }
    }else{
        if(neighbors == 1 || neighbors == 3){
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
Cell::Cell(char alive){
    if(alive == '*' || alive == '.'){
        p = new ConwayCell(alive);
    }else if(((alive >= '0') && (alive <= '9')) || (alive == '+') || (alive == '-')){
        p = new FredkinCell(alive);
    }
}

Cell::Cell(const Cell& other): p(other.p->clone()){}

Cell::~Cell(){delete p;}

bool Cell::diag(){return p->diag();}

Cell& Cell::operator=(Cell other){
    std::cout << " here " << std::endl;
    std::swap((*this).p, other.p);
    return *this;
}

bool Cell::deadOrAlive(int neighbors){
   return p->deadOrAlive(neighbors);
}

void Cell::execute(){
    p->execute();
    if(p->getAlive()){
        if(FredkinCell* f = dynamic_cast<FredkinCell*>(p) ){
            if(f->amITwoYears() == 0){
                delete p;
                p = new ConwayCell('*');
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



