#ifndef Life_h
#define Life_h

//----------
// includes
//----------

#include <iostream>
#include <vector>
#include <string> 
#include <cstring>
#include <unordered_map>


//-------
// enums
//-------

enum cell_t {CONWAY, FREDKIN};
enum dir_t {N, NE, E, SE, S, SW, W, NW};


//--------------
// AbstractCell
//--------------

class AbstractCell{
    public:

        //--------------
        // Constructor
        //--------------

        AbstractCell();
        
        //--------------
        // Constructor
        //--------------

        /**
         * creation of abstract cell with life state and type
         * @param cellType enum specifying type of cell
         * @param alive dead or alive
         */

        AbstractCell(cell_t cellType, bool alive);


        //-------------
        // Destructor
        //-------------

        virtual ~AbstractCell();
        
        //--------------
        // deadOrAlive
        //--------------

        /**
         * determine cell state based on cell criteria
         * sets to change for next generation
         * @param neighbors vector of neighbors around current cell
         * @return dead or alive 
         */

        virtual bool deadOrAlive(int neighbors);
        
        //---------
        // execute
        //---------

        /**
         * changes state of cell
         */

        virtual void execute();

        //--------------
        // printStatus
        //--------------

        /**
         * print cell depending on its type and state
         * @param w ostream writes to console
         */

        virtual void printStatus(std::ostream& w);
        
        //-------
        // diag
        //-------

        /**
         * checks if needs diagonal or not
         * @return needs diagonals or not
         */

        virtual bool diag() = 0;

        //-----------
        // getAlive
        //-----------

        /**
         * get current cell state
         * @return bool that determines whether cell is dead or alive
         */
        bool getAlive();

        //--------
        // clone
        //--------

        /**
         * create exact copy of object
         * @return exact copy of return object
         */

        virtual AbstractCell* clone() = 0;

    protected:
        bool _alive;
        bool _stateToChange;
        cell_t _cellType;



};



//------------
// ConwayCell
//------------

class ConwayCell : public AbstractCell{

    public:

        //--------------
        // Constructor
        //--------------

        ConwayCell();

        //--------------
        // Constructor
        //--------------

        /**
         * creation of conway cell with state
         * @param alive char * or -
         */

        ConwayCell(char alive);
        
        //--------------
        // Destructor
        //--------------

        ~ConwayCell();
        

        //--------------
        // printStatus
        //--------------

        /**
         * prints cell depending on its state
         * @param w ostream
         */

        void printStatus(std::ostream& w);
       

        //--------------
        // deadOrAlive
        //--------------

        /**
         * determine cell state based on cell criteria
         * sets to change for next generation
         * @param neighbors vector of neighbors around current cell
         * @return dead or alive 
         */

        bool deadOrAlive(int neighbors);
       
        //---------
        // execute
        //---------

        /**
         * changes state of cell
         */

        void execute();

        //-------
        // diag
        //-------

        /**
         * checks if needs diagonal or not
         * @return needs diagonals or not
         */

         bool diag();

        //--------
        // clone
        //--------

        /**
         * create exact copy of object
         * @return exact copy of return object
         */

        ConwayCell* clone();
};


//-------------
// FredkinCell
//-------------

class FredkinCell : public AbstractCell{
    public:
        FredkinCell();

        //-------------
        // Constructor
        //-------------

        /**
         * @param alive 0 >=, +, -, <=9
         */

        FredkinCell(char alive);

        ~FredkinCell();

        //-------------
        // amITwoYears
        //-------------

        /**
         * @return -1, 0, 1 <, ==, >
         */

        int amITwoYears();
      
        //--------------
        // deadOrAlive
        //--------------

        /**
         * determine cell state based on cell criteria
         * sets to change for next generation
         * @param neighbors vector of neighbors around current cell
         * @return dead or alive 
         */
        bool deadOrAlive(int neighbors);
        
        //-------
        // diag
        //-------

        /**
         * checks if needs diagonal or not
         * @return needs diagonals or not
         */

        bool diag();

        //--------------
        // printStatus
        //--------------

        /**
         * prints cell depending on its state
         * @param w ostream
         */

        void printStatus(std::ostream& w);

        //---------
        // execute
        //---------

        /**
         * changes state of cell
         */

        void execute();
        

        //--------
        // clone
        //--------

        /**
         * create exact copy of object
         * @return exact copy of return object
         */

        FredkinCell* clone();
    private:
        int _age;

};



//-------
// Cell
//-------

class Cell{
    public:

        //-------------
        // Constructor
        //-------------

        Cell();

        //-------------
        // Constructor
        //-------------

        /**
         * construct cell with specified state 
         * @param alive char specifying which cell to instantiate based on type of char
         */

        Cell(char alive);

        //------------------
        // Copy Constructor
        //------------------

        /**
         * copies param object's data members
         * @param other object to copy
         */

        Cell(const Cell& other);

        //-----------------
        // Copy Assignment
        //-----------------

        /**
         * creates exact copy of object
         * @param other object to copy
         */

        Cell& operator=(Cell other);

        //--------------
        // deadOrAlive
        //--------------

        /**
         * call respective cell's deadOrAlive method
         * @param neighbors vector of neighbors around current cell
         * @return dead or alive 
         */

        bool deadOrAlive(int neighbors);
      

        //--------------
        // getAlive
        //--------------

        /**
         * call respective cell's getAlive method
         * @return current state of cell
         */

        bool getAlive();        

        //--------------
        // printStatus
        //--------------

        /**
         * call respective cell's printStatus
         * @param w ostream
         */

        void printStatus(std::ostream& w);

        //----------
        // execute
        //----------

        /**
         * call respective cell's execute
         */

        void execute();

        //-------
        // diag
        //-------

        /**
         * checks if needs diagonal or not
         * @return needs diagonals or not
         */

        bool diag();

        //--------------
        // Destructor
        //--------------

        ~Cell();

    private:
        AbstractCell* p;

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

        Life(const int& y, const int& x): 
                    _x(x), _y(y), _size(_x*_y), _gen_gone(0), _pop(0){}


        //--------------
        // prepareBoard
        //--------------

        /**
         * read initial board from istream
         * @param r istream reader 
         */

        void prepareBoard(std::istream& r){
            for(int i = 0; i < _y; ++i){
                std::vector<T> temp;
                _board.push_back(temp);

                r.ignore(80, '\n');
                
                while((r.peek() != '\n') && (r.peek() != EOF)){
                    char k;
                    r >> k;
                
                    bool alive = false;
                
                    if(k == '.'){
                        alive = false;
                    }else if(k == '*'){
                        alive = true;
                    }else if(k == '-'){
                        alive = false;
                    }else if( (k >= '0' && k <= '9') || (k == '+')){
                        alive = true;
                    }
                    _board[i].push_back(T(k));
                    if(alive){
                        ++_pop;
                    }
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

            int tempPop = 0;
            for(int i = 0; i < _y; ++i){
                for(int j=0; j < _x; ++j){

                    bool alive = _board[i][j].deadOrAlive(find_neighbors(i, j, _board[i][j].diag()));
                    if(alive){
                        ++tempPop;
                    }
                }
            }

            for(int i = 0; i < _y; ++i){
                for(int j=0; j < _x; ++j){
                    _board[i][j].execute();
                }
            }
            _pop = tempPop;
            ++_gen_gone;
        }


        //-----------------
        // find_neighbors
        //-----------------

        /**
         * get all 8 neighbors of current cell
         * @param row int y position in 2d vector
         * @param col int x position in 2d vector
         * @param needDiagonal bool checks to see if we need to calculate diagonals
         * @return vector of 8 neighbors of current cell
         */

        int find_neighbors(int row, int col, bool needDiagonal){
            int neighbors = 0;
            if(needDiagonal)
                neighbors += statusOfNeighbor(row, col, NE) + statusOfNeighbor(row, col, SE) + 
                           statusOfNeighbor(row, col, SW) + statusOfNeighbor(row, col, NW);
            neighbors += statusOfNeighbor(row, col, N) + statusOfNeighbor(row, col, E) +
                         statusOfNeighbor(row, col, S) + statusOfNeighbor(row, col, W);
            return neighbors;
        }

        //------------------
        // statusOfNeighbor
        //------------------

        /**
         * get state of specified neighbor
         * @param row int y position in 2d vector
         * @param col int x position in 2d vector
         * @param dir state of neighbor to acquire in that direction
         * @return state of specified neighbor 
         */

        bool statusOfNeighbor(int row, int col, dir_t dir){
            int n_col = col;
            int n_row = row;

            switch(dir) {
                case N:
                    n_row = row - 1;
                    break;
                case NE:
                    n_row = row - 1;
                    n_col = col + 1;
                    break;
                case E:
                    n_col = col + 1;
                    break;
                case SE:
                    n_row = row + 1;
                    n_col = col + 1;
                    break;
                case S:
                    n_row = row + 1;
                    break;
                case SW:
                    n_row = row + 1;
                    n_col = col - 1;
                    break;
                case W:
                    n_col = col - 1;
                    break;
                case NW:
                    n_row = row - 1;
                    n_col = col - 1;
                    break;
            }


            if(outOfBounds(n_row, n_col)){
                return false;
            }
            return _board[n_row][n_col].getAlive();
        }

        //--------------
        // outOfBounds
        //--------------

        /**
         * checks to see if coordinates are out of bounds of _board in 2d sense
         * @param rowToCheck int row index to check
         * @param colToCheck int col index to check
         * @return true if out of bounds
         */

        bool outOfBounds(int rowToCheck, int colToCheck){
            int col = colToCheck;
            int row = rowToCheck;
            return row < 0 || row >= _y || col < 0 || col >= _x;

        }

        //------------
        // printGrid
        //------------

        /**
         * print current generation's board
         * @param w ostream 
         */

        void printGrid(std::ostream& w){
            w << std::endl;

            w << "Generation = " << _gen_gone << ", "
              << "Population = " << _pop << "." << std::endl;
            for(int i = 0; i < _y; ++i){
                for(int j = 0; j < _x; ++j){
                     _board[i][j].printStatus(w);
                }
                w << std::endl;
            }
        }


    private:
        const int _x;
        const int _y;
        const int _size;        //total size of _board
        int _gen_gone;           //generations gone by
        int _pop;               //population
        std::vector<std::vector<T>> _board;  //board of cells

    };

#endif //Life_h
