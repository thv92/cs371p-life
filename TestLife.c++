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


TEST(Cell, test_cell_constructor_1){
    Cell k(true);
    ASSERT_EQ(k.getAlive(), true);
}









































