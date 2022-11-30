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
//us_demo.cpp, CAN SEARCH SHORTEST PATH FROM ANY NODE TO US, ALSO TRIMS DOWN NODES USING BFS
void BFS(std::map<int, std::vector<int>>& adj, std::map<int, bool>& visited, std::unordered_set<int>& nodes, std::map<int, int>& predecessor, int start, int bound) {
  
}
int main() {
  static std::map<int,std::string> titles;
  Graph graph("../data/finaladj.txt");
  titles = load_titles("../data/finaltitles.txt", graph);
  std::map<int, int> predecessor = graph.shortest_paths(2038044);
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
