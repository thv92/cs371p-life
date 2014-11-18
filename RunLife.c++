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
    
    ConwayCell as(true);




    std::cout << name1 << std::endl;
    std::cout << y1 << " " << x1 << std::endl;    
    Life<ConwayCell> board1(y1, x1, 12); 
    board1.prepareBoard(std::cin);

    board1.simulate(std::cout);



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
    Life<ConwayCell> board2(y2, x2, 28); 
    board2.prepareBoard(std::cin);



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

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    // ----------
    // Cell 20x20
    // ----------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    return 0;}
