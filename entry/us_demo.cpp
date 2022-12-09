#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_set>
#include<sstream>
#include <queue>
#include "utils.h"
#include "graph.h"
/** us_demo.cpp
 * demo file that prints out a shortest path from a BFS starting at the "United States"
 * Can search for shortest path to multiple nodes (while loop)
 * Searching terminates when "-1" is entered
*/

int main() {
  static std::map<int,std::string> titles;
  Graph graph("../data/finaladj.txt", 29992);
  titles = load_titles("../data/finaltitles.txt", graph, 29992);
  std::map<int, int> predecessor = graph.BFS(2038044);
  while (true) {
    std::cout << "Search: ";
    int input;
    std::cin >> input;
    if (input == -1) {
      break;
    }
    int current = input;
    int steps = 0;
    while (current != 2038044 && steps < 5) {
      std::cout << titles[predecessor[current]] << '\n';
      current = predecessor[current];
      steps++;
    }
  }
}
