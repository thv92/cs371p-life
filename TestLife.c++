#define private public
#define protected public

//----------
// includes
// ---------

#include "Life.h"
#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <utility>  // pair

#include "gtest/gtest.h"

using namespace std;

//ConwayCell

//Constructor

TEST(ConwayCell, test_conway_1){
    ConwayCell k('*');
    ASSERT_EQ(k._alive, true);
}

TEST(ConwayCell, test_conway_2){
    ConwayCell k('.');
    ASSERT_EQ(k._cellType, CONWAY);
}

TEST(ConwayCell, test_conway_3){
    ConwayCell k('.');
    ASSERT_EQ(k._stateToChange, 0);
}

//printStatus

TEST(ConwayCell, test_conway_4){
    ConwayCell k('*');
    std::ostringstream w;
    k.printStatus(w);
    ASSERT_EQ(w.str(), "*");
}

TEST(ConwayCell, test_conway_5){
    ConwayCell k('.');
    std::ostringstream w;
    k.printStatus(w);
    ASSERT_EQ(w.str(), ".");
}    

TEST(ConwayCell, test_conway_6){
    ConwayCell k('*');
    std::ostringstream w;
    k.printStatus(w);
    ASSERT_EQ(w.str(), "*");

    w.str("");
    w.clear();

    k.deadOrAlive(0);
    ASSERT_EQ(k._stateToChange, false);

    k.execute();
    
    k.printStatus(w);
    ASSERT_EQ(k.getAlive(), false);
    ASSERT_EQ(w.str(), ".");
}

//deadOrAlive

TEST(ConwayCell, test_conway_7){
    ConwayCell k('.');
    k.deadOrAlive(3);
    k.execute();

    ASSERT_EQ(k.getAlive(), true);
}  

TEST(ConwayCell, test_conway_8){
    ConwayCell k('*');
    k.deadOrAlive(1);
    k.execute();

    ASSERT_EQ(k.getAlive(), false);
}

TEST(ConwayCell, test_conway_9){
    ConwayCell k('.');
    k.deadOrAlive(4);
    k.execute();

    ASSERT_EQ(k.getAlive(), false);
}

//execute

TEST(ConwayCell, test_conway_10){
    ConwayCell k('*');
    k.deadOrAlive(1);
    ASSERT_NE(k.getAlive(), k._stateToChange);
    k.execute();

    ASSERT_EQ(k.getAlive(), k._stateToChange);
}

TEST(ConwayCell, test_conway_11){
    ConwayCell k('.');
    k.deadOrAlive(3);
    ASSERT_NE(k.getAlive(), k._stateToChange);
    k.execute();

    ASSERT_EQ(k.getAlive(), k._stateToChange);
}

TEST(ConwayCell, test_conway_12){
    ConwayCell k('*');
    k.deadOrAlive(3);
    ASSERT_EQ(k.getAlive(), k._stateToChange);
    k.execute();
    ASSERT_EQ(k.getAlive(), k._stateToChange);

    k.deadOrAlive(1);
    ASSERT_NE(k.getAlive(), k._stateToChange);
    k.execute();
    ASSERT_EQ(k.getAlive(), k._stateToChange);
}

//clone

TEST(ConwayCell, test_conway_13){
    ConwayCell k('*');
    ConwayCell* p = k.clone();
    ASSERT_EQ(p->_cellType, CONWAY);
    ASSERT_EQ(p->_alive, true);
    delete p;
}


TEST(ConwayCell, test_conway_14){
    ConwayCell k('.');
    ConwayCell* p = k.clone();
    ASSERT_EQ(p->_cellType, CONWAY);
    ASSERT_EQ(p->_alive, false);
    delete p;
}

TEST(ConwayCell, test_conway_15){
    ConwayCell k('*');
    ConwayCell* p = k.clone();
    ASSERT_EQ(p->_cellType, CONWAY);
    ASSERT_EQ(p->_alive, true);

    p->deadOrAlive(3);
    p->execute();
    ASSERT_EQ(p->getAlive(), true);
    
    std::ostringstream w;
    p->printStatus(w);
    ASSERT_EQ(w.str(), "*");

    w.str("");
    w.clear();

    p->deadOrAlive(4);
    p->execute();
    ASSERT_EQ(p->getAlive(), false);

    p->printStatus(w);
    ASSERT_EQ(w.str(), ".");

    p->deadOrAlive(3);
    p->execute();
    ASSERT_EQ(p->getAlive(), true);
    delete p;
}

TEST(ConwayCell, test_conway_16){
    ConwayCell k('*');
    ASSERT_EQ(k.diag(), true);
}


//FredkinCell

//Constructor
TEST(FredkinCell, test_fredkin_1){
    FredkinCell k('0');
    ASSERT_EQ(k.getAlive(), true);
}

TEST(FredkinCell, test_fredkin_2){
    FredkinCell k('-');
    ASSERT_EQ(k.getAlive(), false);
}

TEST(FredkinCell, test_fredkin_3){
    FredkinCell k('0');
    std::ostringstream w;
    ASSERT_EQ(k.getAlive(), true);
    k.printStatus(w);
    ASSERT_EQ(w.str(), "0");
    ASSERT_EQ(k._age, 0);
    ASSERT_EQ(k._cellType, FREDKIN);
}

//diag

TEST(FredkinCell, test_fredkin_4){
    FredkinCell k('-');
    ASSERT_EQ(k.diag(), false);
}

TEST(FredkinCell, test_fredkin_5){
    FredkinCell k('0');
    ASSERT_EQ(k.diag(), false);
}


//printStatus

TEST(FredkinCell, test_fredkin_6){
    FredkinCell k('0');
    std::ostringstream w;
    k.printStatus(w);
    ASSERT_EQ(w.str(), "0");
}

TEST(FredkinCell, test_fredkin_7){
    FredkinCell k('0');
    std::ostringstream w;
    k.printStatus(w);

    ASSERT_EQ(w.str(), "0");

    w.str("");
    w.clear();

    k.deadOrAlive(2);
    k.execute();

    k.printStatus(w);

    ASSERT_EQ(w.str(), "-");
}

TEST(FredkinCell, test_fredkin_8){
    FredkinCell k('-');
    std::ostringstream w;

    k.printStatus(w);

    ASSERT_EQ(w.str(), "-");
}

//amITwoYears

TEST(FredkinCell, test_fredkin_9){
    FredkinCell k('0');
    ASSERT_EQ(k.amITwoYears(), -1);
}

TEST(FredkinCell, test_fredkin_10){
    FredkinCell k('0');
    k.deadOrAlive(3);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), -1);
    k.deadOrAlive(3);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), 0);
}

TEST(FredkinCell, test_fredkin_11){
    FredkinCell k('0');
    k.deadOrAlive(3);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), -1);
    k.deadOrAlive(0);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), -1);
    k.deadOrAlive(3);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), -1);
    k.deadOrAlive(3);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), 0);
}

TEST(FredkinCell, test_fredkin_12){
    FredkinCell k('0');
    k.deadOrAlive(3);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), -1);
    
    k.deadOrAlive(0);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), -1);

    k.deadOrAlive(3);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), -1);
    
    k.deadOrAlive(3);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), 0);

    k.deadOrAlive(3);
    k.execute();
    ASSERT_EQ(k.amITwoYears(), 1);
}

//deadOrAlive

TEST(FredkinCell, test_fredkin_13){
    FredkinCell k('-');
    k.deadOrAlive(3);
    k.execute();

    ASSERT_EQ(k.getAlive(), true);
}  

TEST(FredkinCell, test_fredkin_14){
    FredkinCell k('0');
    k.deadOrAlive(0);
    k.execute();

    ASSERT_EQ(k.getAlive(), false);
}

TEST(FredkinCell, test_fredkin_15){
    FredkinCell k('-');
    k.deadOrAlive(4);
    k.execute();

    ASSERT_EQ(k.getAlive(), false);
}

//execute

TEST(FredkinCell, test_fredkin_16){
    FredkinCell k('0');
    k.deadOrAlive(0);
    ASSERT_NE(k.getAlive(), k._stateToChange);
    k.execute();

    ASSERT_EQ(k.getAlive(), k._stateToChange);
}

TEST(FredkinCell, test_fredkin_17){
    FredkinCell k('-');
    k.deadOrAlive(3);
    ASSERT_NE(k.getAlive(), k._stateToChange);
    k.execute();

    ASSERT_EQ(k.getAlive(), k._stateToChange);
}

TEST(FredkinCell, test_fredkin_18){
    FredkinCell k('0');
    k.deadOrAlive(3);
    ASSERT_EQ(k.getAlive(), k._stateToChange);
    k.execute();
    ASSERT_EQ(k.getAlive(), k._stateToChange);

    k.deadOrAlive(2);
    ASSERT_NE(k.getAlive(), k._stateToChange);
    k.execute();
    ASSERT_EQ(k.getAlive(), k._stateToChange);
}

//clone

TEST(FredkinCell, test_fredkin_19){
    FredkinCell k('0');
    FredkinCell* p = k.clone();
    ASSERT_EQ(p->_cellType, FREDKIN);
    ASSERT_EQ(p->_alive, true);

    delete p;
}


TEST(FredkinCell, test_fredkin_20){
    FredkinCell k('-');
    FredkinCell* p = k.clone();
    ASSERT_EQ(p->_cellType, FREDKIN);
    ASSERT_EQ(p->_alive, false);

    delete p;
}

TEST(FredkinCell, test_fredkin_21){
    FredkinCell k('0');
    FredkinCell* p = k.clone();
    ASSERT_EQ(p->_cellType, FREDKIN);
    ASSERT_EQ(p->_alive, true);

    p->deadOrAlive(3);
    p->execute();
    ASSERT_EQ(p->getAlive(), true);
    
    std::ostringstream w;
    p->printStatus(w);
    ASSERT_EQ(w.str(), "1");

    w.str("");
    w.clear();

    p->deadOrAlive(4);
    p->execute();
    ASSERT_EQ(p->getAlive(), false);

    p->printStatus(w);
    ASSERT_EQ(w.str(), "-");

    p->deadOrAlive(3);
    p->execute();
    ASSERT_EQ(p->getAlive(), true);

    delete p;
}

//Cell

TEST(Cell, test_cell_1){
    Cell k('0');
    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), true);
}

TEST(Cell, test_cell_2){
    Cell k('-');
    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), false);
}

TEST(Cell, test_cell_3){
    Cell k('-');
    ASSERT_EQ(k.diag(), false);
}

TEST(Cell, test_cell_4){
    Cell k('0');
    k.deadOrAlive(1);
    k.execute();

    k.deadOrAlive(1);
    k.execute();

    ASSERT_EQ(k.p->_cellType, CONWAY);
    ASSERT_EQ(k.getAlive(), true);

    ASSERT_EQ(k.diag(), true);
}

TEST(Cell, test_cell_5){
    Cell k('0');
    k.deadOrAlive(0);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), false);

    k.deadOrAlive(1);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), true);

    std::ostringstream w;
    k.printStatus(w);
    ASSERT_EQ(w.str(), "0");
}

TEST(Cell, test_cell_6){
    Cell k('-');
    k.deadOrAlive(1);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), true);

    k.deadOrAlive(0);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), false);

    k.deadOrAlive(1);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), true);

    std::ostringstream w;
    k.printStatus(w);
    ASSERT_EQ(w.str(), "0");

    k.deadOrAlive(4);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), false);

    w.str("");
    w.clear();

    k.printStatus(w);
    ASSERT_EQ(w.str(), "-");

    k.deadOrAlive(3);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), true);
}

TEST(Cell, test_cell_7){
    Cell k('-');
    k.deadOrAlive(1);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), true);

    k.deadOrAlive(0);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), false);

    k.deadOrAlive(1);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), true);

    std::ostringstream w;
    k.printStatus(w);
    ASSERT_EQ(w.str(), "0");

    k.deadOrAlive(1);
    k.execute();

    ASSERT_EQ(k.p->_cellType, FREDKIN);
    ASSERT_EQ(k.getAlive(), true);

    w.str("");
    w.clear();

    k.printStatus(w);
    ASSERT_EQ(w.str(), "1");

    k.deadOrAlive(3);
    k.execute();

    ASSERT_EQ(k.p->_cellType, CONWAY);
    ASSERT_EQ(k.getAlive(), true);

    k.deadOrAlive(1);
    k.execute();

    ASSERT_EQ(k.p->_cellType, CONWAY);
    ASSERT_EQ(k.getAlive(), false);

}


TEST(Cell, test_cell_8){
    Cell k('*');
    ASSERT_EQ(k.p->_cellType, CONWAY);
    ASSERT_EQ(k.p->_alive, true);
    ASSERT_EQ(k.diag(), true);
}


//Life



TEST(Life, test_life_1){
    int x = 19;
    int y = 20;
    Life<Cell> k(y, x);
    ASSERT_EQ(k._x, x);
    ASSERT_EQ(k._y, y);
    ASSERT_EQ(k._size, x*y);
}

TEST(Life, test_life_2){
    int x = 100;
    int y = 20;
    Life<ConwayCell> k(y, x);
    ASSERT_EQ(k._x, x);
    ASSERT_EQ(k._y, y);
    ASSERT_EQ(k._size, x*y);
}

TEST(Life, test_life_3){
    int x = 100;
    int y = 152;
    Life<FredkinCell> k(y, x);
    ASSERT_EQ(k._x, x);
    ASSERT_EQ(k._y, y);
    ASSERT_EQ(k._size, x*y);
}

TEST(Life, test_life_4){
    int x = 2;
    int y = 2;
    Life<ConwayCell> k(y, x);

    std::istringstream i("\n**\n..");
    k.prepareBoard(i);
    std::ostringstream w;
    k.simulate();
    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 1, Population = 0.\n..\n..\n");
}


TEST(Life, test_life_5){
    int x = 3;
    int y = 3;
    Life<ConwayCell> k(y, x);

    std::istringstream i("\n*.*\n..*\n*..");
    k.prepareBoard(i);
    std::ostringstream w;
    k.simulate();
    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 1, Population = 1.\n.*.\n...\n...\n");
}

TEST(Life, test_life_6){
    int x = 3;
    int y = 3;
    Life<ConwayCell> k(y, x);

    std::istringstream i("\n..*\n***\n*..");
    k.prepareBoard(i);
    std::ostringstream w;
    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 0, Population = 5.\n..*\n***\n*..\n");
}

TEST(Life, test_life_7){
    int x = 3;
    int y = 3;
    Life<ConwayCell> k(y, x);

    std::istringstream i("\n..*\n***\n*..");
    k.prepareBoard(i);
    std::ostringstream w;
    
    for(int i = 0; i <= 4; ++i){
        if(i == 4)
            k.printGrid(w);
        k.simulate();
    }
    ASSERT_EQ(w.str(), "\nGeneration = 4, Population = 0.\n...\n...\n...\n");
}


TEST(Life, test_life_8){
    int x = 3;
    int y = 3;
    Life<ConwayCell> k(y, x);

    std::istringstream i("\n***\n***\n*..");
    k.prepareBoard(i);
    std::ostringstream w;
    
    for(int i = 0; i <= 4; ++i){
        if(i == 4)
            k.printGrid(w);
        k.simulate();
    }
    ASSERT_EQ(w.str(), "\nGeneration = 4, Population = 0.\n...\n...\n...\n");
}

TEST(Life, test_life_9){
    int x = 5;
    int y = 5;
    Life<ConwayCell> k(y, x);

    std::istringstream i("\n***..\n**..*\n*.**.\n*.*.*\n*.***.");
    k.prepareBoard(i);
    std::ostringstream w;
    
    for(int i = 0; i <= 7; ++i){
        if(i == 7)
            k.printGrid(w);
        k.simulate();
    }
    ASSERT_EQ(w.str(), "\nGeneration = 7, Population = 5.\n.....\n..*..\n.*.*.\n.*...\n..*..\n");
}




TEST(Life, test_life_10){
    int x = 3;
    int y = 3;
    Life<FredkinCell> k(y, x);

    std::istringstream i("\n---\n---\n00-");
    k.prepareBoard(i);
    std::ostringstream w;
    k.simulate();
    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 1, Population = 5.\n---\n00-\n110\n");
}


TEST(Life, test_life_11){
    int x = 3;
    int y = 3;
    Life<FredkinCell> k(y, x);

    std::istringstream i("\n-0-\n---\n00-");
    k.prepareBoard(i);
    std::ostringstream w;
    k.simulate();
    k.simulate();
    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 2, Population = 2.\n1--\n---\n--1\n");
}


TEST(Life, test_life_12){
    int x = 3;
    int y = 3;
    Life<FredkinCell> k(y, x);

    std::istringstream i("\n-0-\n0-0\n00-");
    k.prepareBoard(i);
    std::ostringstream w;
    k.simulate();
    k.simulate();
    k.simulate();
    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 3, Population = 4.\n-0-\n1-0\n-1-\n");
}


TEST(Life, test_life_13){
    int x = 4;
    int y = 4;
    Life<FredkinCell> k(y, x);

    std::istringstream i("\n-0-0\n0--0\n0-0-\n0000");
    k.prepareBoard(i);
    std::ostringstream w;

    for(int i = 0; i <= 10; ++i){
        k.simulate();
    }

    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 11, Population = 10.\n--9+\n10--\n0+-+\n-011\n");
}

TEST(Life, test_life_14){
    int x = 2;
    int y = 2;
    Life<Cell> k(y, x);

    std::istringstream i("\n--\n00");
    std::ostringstream w;

    k.prepareBoard(i);
    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 0, Population = 2.\n--\n00\n");
}

TEST(Life, test_life_15){
    int x = 2;
    int y = 2;
    Life<Cell> k(y, x);

    std::istringstream i("\n--\n00");
    std::ostringstream w;

    k.prepareBoard(i);

    for(int i = 0; i <= 5; ++i)
        k.simulate();


    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 6, Population = 0.\n--\n--\n");
}

TEST(Life, test_life_16){
    int x = 3;
    int y = 3;
    Life<Cell> k(y, x);

    std::istringstream i("\n000\n-0-\n0-0");
    std::ostringstream w;

    k.prepareBoard(i);

    for(int i = 0; i <= 5; ++i)
        k.simulate();


    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 6, Population = 0.\n-.-\n---\n---\n");
}

TEST(Life, test_life_17){
    int x = 3;
    int y = 4;
    Life<Cell> k(y, x);

    std::istringstream i("\n000\n-0-\n0-0\n00-");
    std::ostringstream w;

    k.prepareBoard(i);

    for(int i = 0; i <= 5; ++i)
        k.simulate();


    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 6, Population = 2.\n...\n1.-\n..-\n-1-\n");
}


TEST(Life, test_life_18){
    int x = 6;
    int y = 6;
    Life<Cell> k(y, x);

    std::istringstream i("\n00-0-0\n0-0-0-\n0-00-0\n00000-\n00-00-\n0000--");
    std::ostringstream w;

    k.prepareBoard(i);

    for(int i = 0; i <= 20; ++i)
        k.simulate();


    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 21, Population = 10.\n......\n.....1\n..*.*.\n.*..*.\n*...*.\n.***.-\n");
}


TEST(Life, test_life_19){
    int x = 6;
    int y = 6;
    Life<Cell> k(y, x);

    std::istringstream i("\n00-0-0\n0-0-0-\n0-00-0\n00000-\n00-00-\n00**--");
    std::ostringstream w;

    k.prepareBoard(i);

    for(int i = 0; i <= 20; ++i)
        k.simulate();


    k.printGrid(w);
    ASSERT_EQ(w.str(), "\nGeneration = 21, Population = 15.\n..***.\n.*..*1\n****..\n.*...*\n..*...\n...*.*\n");
}