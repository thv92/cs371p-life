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

#define DEBUGLIFE false
#define DEBUGC false
//-------
// enums
//-------

enum cell_t {CONWAY, FREDKIN, IDK};
enum dir_t {N, NE, E, SE, S, SW, W, NW};
enum da_t {DEAD, ALIVE};


//--------------
// AbstractCell
//--------------

class AbstractCell{
    public:
        AbstractCell();
        AbstractCell(cell_t cellType, bool alive);
        virtual ~AbstractCell();
        virtual bool deadOrAlive(std::vector<bool> neighbors);
        bool getAlive();
    protected:
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

class ConwayCell : public AbstractCell{
    public:
        ConwayCell();
        ConwayCell(bool alive);
        ~ConwayCell();

        bool deadOrAlive(std::vector<bool> neighbors);
    private:


};


//-------------
// FredkinCell
//-------------

class FredkinCell : public AbstractCell{
    public:
        FredkinCell();
        FredkinCell(bool alive);
        ~FredkinCell();

        bool deadOrAlive(std::vector<bool> neighbors);

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
                    _x(x), _y(y), _size(_x*_y), _gen(gen), _pop(0), _board(x*y){}


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
                    bool alive = k == '.' ? false : true;
                    
                    _board[index] = T(alive);
                    
                    if(alive){
                        ++_pop;
                    }

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

        void simulate(std::ostream& w){

            int genGone = 0;
            while(genGone <= _gen){
                printGrid(w, genGone);
                std::vector<T> tempBoard(_size);
                int tempPop = 0;
                for(int i = 0; i < _size; ++i){
                    // std::pair<int, int> test = changeToCoord(i);
                    // std::cout << "("<< test.first<< ", "<< test.second<<")"<<std::endl;
                    
                    if(_board[i].deadOrAlive(find_neighbors(i))){
                        tempBoard[i] = T(true);
                        ++tempPop;
                    }else{
                        tempBoard[i] = T(false);
                    }

                    // break;
                }
                _pop = tempPop;
                _board = tempBoard;
                // break;   
                ++genGone;
            }

        }


        std::vector<bool> find_neighbors(int pos){
            std::vector<bool> n;
            n.push_back(statusOfNeighbor(pos, N));
            n.push_back(statusOfNeighbor(pos, NE));
            n.push_back(statusOfNeighbor(pos, E));
            n.push_back(statusOfNeighbor(pos, SE));
            n.push_back(statusOfNeighbor(pos, S));
            n.push_back(statusOfNeighbor(pos, SW));
            n.push_back(statusOfNeighbor(pos, W));
            n.push_back(statusOfNeighbor(pos, NW));

            if(DEBUGLIFE)
            std::cout << n.size() << std::endl;
            return n;
        }

        bool statusOfNeighbor(int pos, dir_t dir){
            std::pair<int, int> curCoord = changeToCoord(pos);

            int n_col = curCoord.first;
            int n_row = curCoord.second;

            switch(dir) {
                case N:
                    n_row = curCoord.second - 1;
                    break;
                case NE:
                    n_row = curCoord.second - 1;
                    n_col = curCoord.first + 1;
                    break;
                case E:
                    n_col = curCoord.first + 1;
                    break;
                case SE:
                    n_row = curCoord.second + 1;
                    n_col = curCoord.first + 1;
                    break;
                case S:
                    n_row = curCoord.second + 1;
                    break;
                case SW:
                    n_row = curCoord.second + 1;
                    n_col = curCoord.first - 1;
                    break;
                case W:
                    n_col = curCoord.first - 1;
                    break;
                case NW:
                    n_row = curCoord.second - 1;
                    n_col = curCoord.first - 1;
                    break;
            }


            if(outOfBounds(std::pair<int, int>(n_col, n_row))){
                return false;
            }
            return _board[changeToPos(std::pair<int, int>(n_col, n_row))].getAlive();
        }

        bool outOfBounds(std::pair<int, int> coord){
            int col = coord.first;
            int row = coord.second;
            return row < 0 || row >= _y || col < 0 || col >= _x;

        }

        std::pair<int, int> changeToCoord(int pos){
            int row = pos/_x;
            int col = pos - (row * _x);
            return std::pair<int,int>(col, row);
        }

        int changeToPos(std::pair<int, int> coord){
            return coord.first + coord.second * _x;
        }

        // index = X + Y * Width;
        // Y = (int)(index / Width)
        // X = index - (Y * Width)

        void printGrid(std::ostream& w, int gen_gone){
            w << "Generation = " << gen_gone << ", "
              << "Population = " << _pop << "." << std::endl;
            

            int i = 0;
            while(i < _size){
                for(int col = 0; col < _x; ++col){
                    ConwayCell &k = _board[i];

                    if(k.getAlive()) {
                        w << "*";
                    }else{
                        w << ".";
                    }
                    ++i;
                }
                w << std::endl;
            }
            w << std::endl;
        }



    private:
        const int _x;
        const int _y;
        const int _size;
        const int _gen;
        int _pop;
        std::vector<T> _board;

    };








#endif //Life_h
