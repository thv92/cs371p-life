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

#define RUN_1 true
#define RUN_2 true
#define RUN_3 true
#define RUN_4 true
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
    


    std::cout << name1 << std::endl;
    std::cout << y1 << " " << x1 << std::endl;    
    Life<ConwayCell> board1(y1, x1); 
    board1.prepareBoard(std::cin);
    if(RUN_1)
    for(int i = 0; i <= 12; ++i){
        board1.printGrid(std::cout, i);
        board1.simulate(std::cout);
    }


    // -----------------
    // Conway Cell 20x29
    // -----------------

    cout << "*** Life<ConwayCell> 20x29 ***" << endl;
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
    

    std::cout << name2 << std::endl;
    std::cout << y2 << " " << x2 << std::endl;    
    Life<ConwayCell> board2(y2, x2); 
    board2.prepareBoard(std::cin);

    if(RUN_2)
    for(int i = 0; i <= 28; ++i){
        if( (i == 0) || ( ( (i%4) == 0) && (i >= 4) ) ){
            board2.printGrid(std::cout, i);
        }
        board2.simulate(std::cout);
    }


    // ------------------
    // Conway Cell 109x69
    // ------------------

    cout << "*** Life<ConwayCell> 109x69 ***" << endl;
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
    

    std::cout << name3 << std::endl;
    std::cout << y3 << " " << x3 << std::endl;    
    Life<ConwayCell> board3(y3, x3); 
    board3.prepareBoard(std::cin);

    if(RUN_3)
    for(int i = 0; i <= 2500; ++i){
        if( i < 10 || i == 283 || i == 323 || i == 2500 ){
            board3.printGrid(std::cout, i);
        }
        board3.simulate(std::cout);
    }





    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
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
    

    std::cout << name4 << std::endl;
    std::cout << y4 << " " << x4 << std::endl;    
    Life<FredkinCell> board4(y4, x4); 
    board4.prepareBoard(std::cin);

    if(RUN_4)
    for(int i = 0; i <= 5; ++i){
        board4.printGrid(std::cout, i);
        board4.simulate(std::cout);
    }








    // ----------
    // Cell 20x20
    // ----------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    return 0;}
