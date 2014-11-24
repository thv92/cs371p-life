//----------
// includes
// ---------

#include "Life.h"
#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <utility>  // pair

#include "gtest/gtest.h"
#define private public
#define protected public

using namespace std;

TEST(ConwayCell, test_conway_constructor_1){
    ConwayCell k(true);
    ASSERT_EQ(k.getAlive(), true);
}

TEST(ConwayCell, test_conway_constructor_2){
    ConwayCell k(false);
    ASSERT_EQ(k.getAlive(), false);
}

TEST(FredkinCell, test_fredkin_constructor_1){
    FredkinCell k(true);
    ASSERT_EQ(k.getAlive(), true);
}

TEST(FredkinCell, test_fredkin_constructor_2){
    FredkinCell k(false);
    ASSERT_EQ(k.getAlive(), false);
}

TEST(FredkinCell, test_fredkin_constructor_3){
    FredkinCell k(true);
    std::ostringstream w;
    ASSERT_EQ(k.getAlive(), true);
    k.printStatus(w);
    ASSERT_EQ(w.str(), "0");
}

TEST(Cell, test_cell_constructor_1){
    Cell k(true);
    ASSERT_EQ(FredkinCell::k.getAlive(), true);
}









































