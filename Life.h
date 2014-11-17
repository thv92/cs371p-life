#ifndef Life_h
#define Life_h

//----------
// includes
//----------

#include <iostream>
#include <vector>
#include <string> 
#include <cstring>

#define DEBUGLIFE true

//-------
// enums
//-------

enum cell_t {CONWAY, FREDKIN, IDK};



//--------------
// AbstractCell
//--------------

class AbstractCell{
    public:
        AbstractCell();
        AbstractCell(cell_t cellType, bool alive);
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
        ConwayCell(bool alive);
        ~ConwayCell();
    private:


};


//-------------
// FredkinCell
//-------------

class FredkinCell : AbstractCell{
    public:
        FredkinCell();
        FredkinCell(bool alive);
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
        
        //------
        // Life
        //------

        /**
         * constructor for life
         * @param x number of rows
         * @param y number of columns
         */

        Life(const int& y, const int& x, const int& gen): 
                    _x(x), _y(y), _size(_x*_y), _gen(gen), _board(x*y){}


        //--------------
        // prepareBoard
        //--------------

        /**
         * read initial board from istream
         * @param r istream reader 
         */

        void prepareBoard(std::istream& r){
            int index = 0;
            for(int i = 0; i < _y; ++i){

                r.ignore(80, '\n');

                while((r.peek() != '\n') && (r.peek() != EOF)){
                    char k;
                    r >> k;

                    //dead = . | alive = something else
                    _board[index] = T(k == '.' ? false : true);
                    ++index;
                }
            }
        }


        //----------
        // simulate
        //----------

        /**
         * simulate life cycle of cells for each generation
         */

        void simulate(){



        }

    private:
        const int _x;
        const int _y;
        const int _size;
        const int _gen;
        std::vector<T> _board;

    };








#endif //Life_h

                // std::string line;
            // getline(r, line);


            // while(strcmp(line.c_str(), "\n") <= 0){
            //     getline(r, line);
            // }

            // while(!line.empty() && line.length() > 0){

            //   std::cout << line << std::endl;



            //   getline(r, line);
            // }