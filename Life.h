#ifndef Life_h
#define Life_h

//----------
// includes
//----------

#include <iostream>
#include <vector>


//-------
// enums
//-------

enum cell_t {CONWAY, FREDKIN, CELL, IDK};


//--------------
// AbstractCell
//--------------

class AbstractCell{
    public:
        AbstractCell();
        AbstractCell(const int& cellType);
        virtual ~AbstractCell();
        virtual bool deadOrAlive();
    private:
        bool _alive;
        cell_t _cellType;


};



//-------
// Cell
//-------

class Cell{
    public:

    private:


};



//------------
// ConwayCell
//------------

class ConwayCell : AbstractCell{
    public:
        ConwayCell();
        ConwayCell(const int& cellType);
        ~ConwayCell();
    private:


};


//-------------
// FredkinCell
//-------------

class FredkinCell : AbstractCell{
    public:
        FredkinCell();
        FredkinCell(const int& cellType);
        ~FredkinCell();
    private:
        int _age;

};


//------
// Life
//------

template<class T>
class Life{
    public:
        Life(const int& y, const int& x);
        void prepareBoard(std::istream& r);
    private:
        const int _x;
        const int _y;
        const int _size;
        std::vector<T> _board;

};








#endif //Life_h