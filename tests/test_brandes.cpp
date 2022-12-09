#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include "graph.h"
using std::cout;
using std::endl;
using std::string;


TEST_CASE("test brandes simple 1") {
    Graph graph("../tests/test_brandes_simple1.txt", 4);
    std::map<int, double> betweeness = graph.brandes();
    REQUIRE(betweeness[1] == 0);
    REQUIRE(betweeness[2] == 2);
    REQUIRE(betweeness[3] == 2);
    REQUIRE(betweeness[4] == 0);
}
TEST_CASE("test brandes simple 2") {
    Graph graph("../tests/test_brandes_simple2.txt", 4);
    std::map<int, double> betweeness = graph.brandes();
    for (int i = 1; i <= 4; i++) {
        REQUIRE(betweeness[i] == 3); //graph is one cycle so all nodes should have the same centrality
    }
}
TEST_CASE("test brandes wheel") {
    Graph graph("../tests/test_brandes_wheel.txt", 7);
    std::map<int, double> betweeness = graph.brandes();
    REQUIRE(betweeness[1] == 30); //30 ordered pairs of the nodes on the outside of the wheel
    for (int i = 2; i <= 7; i++) {
        REQUIRE(betweeness[i] == 0); // check outside of wheel all have betweenness centrality of 0
    }
}
TEST_CASE("test brandes multiple shortest paths") {
    Graph graph("../tests/test_brandes_multiple_paths.txt", 8);
    std::map<int, double> betweeness = graph.brandes();
    //check nodes that aren't on any shortest paths
    REQUIRE(betweeness[1] == 0);
    REQUIRE(betweeness[4] == 0);
    //check middle nodes
    REQUIRE(betweeness[2] == (1.0/2.0) + (1.0/4.0));
    REQUIRE(betweeness[3] == (2.0/4.0) + (1.0/2.0) + 1 + (1.0/2.0));
    REQUIRE(betweeness[5] == 1 + (1.0/2.0) + (2.0/4.0));
    REQUIRE(betweeness[6] == (1.0/4.0) + (1.0/2.0));
    REQUIRE(betweeness[7] == (1.0/4.0) + 1);
    REQUIRE(betweeness[8] == (1.0/4.0) + 1);
}
