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
AbstractCell::AbstractCell(const int& cellType): _cellType(static_cast<cell_t>(cellType)){}
AbstractCell::~AbstractCell(){}

bool AbstractCell::deadOrAlive(){return 0;}


//--------------
// Cell
//--------------






//------------
// ConwayCell
//------------

ConwayCell::ConwayCell(){}
ConwayCell::ConwayCell(const int& cellType): AbstractCell(cellType){}
ConwayCell::~ConwayCell(){}




//-------------
// FredkinCell
//-------------

FredkinCell::FredkinCell(){}
FredkinCell::FredkinCell(const int& cellType): AbstractCell(cellType){}
FredkinCell::~FredkinCell(){}





//------
// Life
//------

template<class T>
Life<T>::Life(const int& y, const int& x): _x(x), _y(y), _size(x*y), _board(x*y){}


template<class T>
void Life<T>::prepareBoard(std::istream& r){
    
    std::string line;
    getline()

    while(true){
        
        if()

        std::cout << k;
        r >> k;

        ++i;
    }




}



    std::string temp;
    getline(r, temp);
    
    // int debug = 0;
    while((strcmp(temp.c_str(), "") > 0 || strcmp(temp.c_str(), " ") > 0) || strcmp(temp.c_str(), "\0") > 0){
        Ballot new_ballot;
        new_ballot.index = 0;

        std::stringstream ssin(temp.c_str()); 

        int index = 0;
        
        while(index < num_candidate){
            int vote;
            ssin >> vote;
            new_ballot.candidate_ballot.push_back(vote);
            index++;
        }
        list_of_ballot.push_back(new_ballot);
        
        if(r.peek() == EOF){
            break;
        }

        getline(r, temp);

    }





template class Life<Cell>;
template class Life<ConwayCell>;
template class Life<FredkinCell>;


