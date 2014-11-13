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

// ----
// main
// ----

int main () {
    using namespace std;

    // ------------------
    // Conway Cell 109x69
    // ------------------

    cout << "*** Life<ConwayCell> 109x69 ***" << endl;
    /*
    read RunLifeConway.in // assume all Conway cells
    Simulate 283 moves.
    Print the first 10 grids (i.e. 0, 1, 2...9).
    Print the 283rd grid.
    Simulate 40 moves.
    Print the 323rd grid.
    Simulate 2177 moves.
    Print the 2500th grid.
    */

    // ------------------
    // Fredkin Cell 20x20
    // ------------------

    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    /*
    read RunLifeFredkin.in // assume all Fredkin cells
    Simulate 5 moves.
    Print every grid (i.e. 0, 1, 2...5)
    */

    // ----------
    // Cell 20x20
    // ----------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
    read RunLifeCell.in // assume all Fredkin cells
    Simulate 5 moves.
    Print every grid (i.e. 0, 1, 2...5)
    */

    return 0;}
