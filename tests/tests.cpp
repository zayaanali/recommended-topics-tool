#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>
#include "../src/graph.cpp"
using std::cout;
using std::endl;
using std::string;


// TEST_CASE("World War II -> United States", "[tag1][tag2]") {
//     // Feel free to use this to put your own test cases.
//     // Look at other test files for inspiration!
//   static std::map<int,std::string> titles;
//   Graph graph("../data/finaladj.txt", 46367);
//   titles = load_titles("../data/finaltitles.txt", graph, 46367);
//   std::map<int, int> predecessor = graph.BFS(2038044);
//   int input = 2693870; //World War II
//   int current = input;
//   int steps = 0;
//   while (current != 2038044 && steps < 5) {
//     current = predecessor[current];
//     steps++;
//   }
//   REQUIRE(current == 2038044); //United States
// }

// TEST_CASE("Einstein Field Equations -> United States", "[tag1][tag2]") {
//     // Feel free to use this to put your own test cases.
//     // Look at other test files for inspiration!
//     static std::map<int,std::string> titles;
//   Graph graph("../data/finaladj.txt", 46367);
//   titles = load_titles("../data/finaltitles.txt", graph, 46367);
//   std::map<int, int> predecessor = graph.BFS(2038044);
  
//     int input = 391789; //Einstein Field Equations
//     int current = input;
//     int steps = 0;
//     while (current != 2038044 && steps < 5) {
//       current = predecessor[current];
//       steps++;
//     }
//     REQUIRE(current == 2038044); //United States
// }

// TEST_CASE("The Dark Knight (Film) -> United States", "[tag1][tag2]") {
//     // Feel free to use this to put your own test cases.
//     // Look at other test files for inspiration!
//     static std::map<int,std::string> titles;
//   Graph graph("../data/finaladj.txt", 46367);
//   titles = load_titles("../data/finaltitles.txt", graph, 46367);
//   std::map<int, int> predecessor = graph.BFS(2038044);
  
//     int input = 2050719; //The Dark Knight (Film)
//     int current = input;
//     int steps = 0;
//     while (current != 2038044 && steps < 5) {
//       current = predecessor[current];
//       steps++;
//     }
//     REQUIRE(current == 2038044); //United States
// }