#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>
#include <unordered_set>
#include "graph.h"
using std::cout;
using std::endl;
using std::string;


// TEST_CASE("test bfs trim 1 step") {
//     Graph graph("../tests/test1.txt", 12);
//     std::vector<int> seeds = {1};
//     std::unordered_set<int> actual = graph.BFS_Trim(seeds, 1);
//     std::unordered_set<int> expected({2, 3, 9, 1});
//     REQUIRE(expected == actual);
// }

// TEST_CASE("test bfs trim 2 steps") {
//     Graph graph("../tests/test1.txt", 12);
//     std::vector<int> seeds = {1};
//     std::unordered_set<int> actual = graph.BFS_Trim(seeds, 2);
//     std::unordered_set<int> expected({2, 3, 9, 1, 8, 4, 10, 12, 7, 6});
//     REQUIRE(expected == actual);
// }

// TEST_CASE("test bfs trim 3 steps") {
//     Graph graph("../tests/test1.txt", 12);
//     std::vector<int> seeds = {1};
//     std::unordered_set<int> actual = graph.BFS_Trim(seeds, 3);
//     std::unordered_set<int> expected({2, 3, 9, 1, 8, 4, 10, 12, 7, 6, 11, 5});
//     REQUIRE(expected == actual);
// }
// TEST_CASE("test bfs trim line 4") {
//     Graph graph("../tests/test2.txt", 12);
//     std::vector<int> seeds = {1};
//     std::unordered_set<int> actual = graph.BFS_Trim(seeds, 4);
//     std::unordered_set<int> expected({1, 2, 3, 4, 5});
//     REQUIRE(expected == actual);
// }

// TEST_CASE("test bfs trim line from middle") {
//     Graph graph("../tests/test2.txt", 12);
//     std::vector<int> seeds = {5};
//     std::unordered_set<int> actual = graph.BFS_Trim(seeds, 4);
//     std::unordered_set<int> expected({5, 6, 7, 8, 9});
//     REQUIRE(expected == actual);
// }

TEST_CASE("Test Strongly Connected Components") {
    Graph graph("../tests/test4.txt", 5);
    graph.getSCCs();
    //REQUIRE(expected == actual);
}