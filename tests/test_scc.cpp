#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>
#include <unordered_set>
#include "graph.h"
using std::cout;
using std::endl;
using std::string;


TEST_CASE("test scc simple 1") {
    Graph graph("../tests/test_scc_simple.txt", 5);
    std::map<int, std::vector<int>> sccs = graph.getSCCs();
    REQUIRE(sccs.size() == 3);
    std::vector<std::unordered_set<int>> expecteds;
    std::unordered_set<int> expected1({0, 1, 2});
    std::unordered_set<int> expected2({3});
    std::unordered_set<int> expected3({4});
    expecteds.push_back(expected1);
    expecteds.push_back(expected2);
    expecteds.push_back(expected3);
    for (int i = 0; i < 3; i++) {
        std::unordered_set<int> actual(sccs[i].begin(), sccs[i].end());
        REQUIRE(actual == expecteds[i]);
    }
}

TEST_CASE("test scc simple 2") {
    Graph graph("../tests/test_scc_simple2.txt", 8);
    std::map<int, std::vector<int>> sccs = graph.getSCCs();
    REQUIRE(sccs.size() == 3);
    std::unordered_set<int> expected1({0});
    std::unordered_set<int> expected2({1,2,3,4});
    std::unordered_set<int> expected3({5,6,7});
    std::vector<std::unordered_set<int>> expecteds;
    expecteds.push_back(expected1);
    expecteds.push_back(expected2);
    expecteds.push_back(expected3);
    for (int i = 0; i < 3; i++) {
        std::unordered_set<int> actual(sccs[i].begin(), sccs[i].end());
        REQUIRE(actual == expecteds[i]);
    }
}