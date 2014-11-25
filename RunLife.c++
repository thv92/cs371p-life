// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2014
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include "Life.h"


// ----
// main
// ----

int main () {
    using namespace std;

    // -----------------
    // Conway Cell 21x13
    // -----------------

    cout << "*** Life<ConwayCell> 21x13 ***" << endl;
    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */

    int y1;
    int x1;
    std::string name1;
    std::cin >> name1;
    std::cin >> y1;
    std::cin >> x1;
    


    Life<ConwayCell> board1(y1, x1); 
    board1.prepareBoard(std::cin);
    for(int i = 0; i <= 12; ++i){
        board1.printGrid(std::cout);
        board1.simulate(std::cout);
    }


    // -----------------
    // Conway Cell 20x29
    // -----------------

    cout << "\n*** Life<ConwayCell> 20x29 ***" << endl;
    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */

    int y2;
    int x2;
    std::string name2;
    std::cin >> name2;
    std::cin >> y2;
    std::cin >> x2;
    

    Life<ConwayCell> board2(y2, x2); 
    board2.prepareBoard(std::cin);
    for(int i = 0; i <= 28; ++i){
        if( (i == 0) || ( ( (i%4) == 0) && (i >= 4) ) ){
            board2.printGrid(std::cout);
        }
        board2.simulate(std::cout);
    }


    // ------------------
    // Conway Cell 109x69
    // ------------------

    cout << "\n*** Life<ConwayCell> 109x69 ***" << endl;
    /*
    Simulate 283 evolutions.
    Print the first 10 grids (i.e. 0, 1, 2, ... 9).
    Print the 283rd grid.
    Simulate 40 evolutions.
    Print the 323rd grid.
    Simulate 2177 evolutions.
    Print the 2500th grid.
    */

    int y3;
    int x3;
    std::string name3;
    std::cin >> name3;
    std::cin >> y3;
    std::cin >> x3;
    

    Life<ConwayCell> board3(y3, x3); 
    board3.prepareBoard(std::cin);
    for(int i = 0; i <= 2500; ++i){
        if( i < 10 || i == 283 || i == 323 || i == 2500 ){
            board3.printGrid(std::cout);
        }
        board3.simulate(std::cout);
    }





    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    cout << "\n*** Life<FredkinCell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    int y4;
    int x4;
    std::string name4;
    std::cin >> name4;
    std::cin >> y4;
    std::cin >> x4;
    

    Life<FredkinCell> board4(y4, x4); 
    board4.prepareBoard(std::cin);
    for(int i = 0; i <= 5; ++i){
        board4.printGrid(std::cout);
        board4.simulate(std::cout);
    }








    // ----------
    // Cell 20x20
    // ----------

    cout << "\n*** Life<Cell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    int y5;
    int x5;
    std::string name5;
    std::cin >> name5;
    std::cin >> y5;
    std::cin >> x5;
    
    Life<Cell> board5(y5, x5); 
    board5.prepareBoard(std::cin);
    for(int i = 0; i <= 5; ++i){
        board5.printGrid(std::cout);
        board5.simulate(std::cout);
    }

    return 0;}
