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
//BFS FILE, TRIMS 130K NODES DOWN TO ~42K CONNECTED GRAPH WITH UNITED STATES AS THE ROOT. OUTPUTS FINAL ADJACENCY LIST AND FINAL TITLES FILES
int main() {
  static std::map<int,std::string> titles;
  std::unordered_set<int> trimmed;
  Graph graph("../data/filteredadj.txt", 131511);
  titles = load_titles("../data/reducedtitles.txt", graph, 131511);
  std::vector<int> topten = {2038044, 3846441, 423902, };
  trimmed = graph.BFS_Trim(topten, 2);
  std::cout << trimmed.size() << '\n';
  std::ofstream Writing("../data/finaladj.txt");
  std::ofstream Writing2("../data/finaltitles.txt");
  for (auto itr = trimmed.begin(); itr != trimmed.end(); itr++) {
    Writing2 << *itr << ',' << titles[*itr] << '\n'; //writes out the final 40K titles
    std::vector<int> adjacent = graph.getAdjacent(*itr);
    std::vector<int> newadj;
    for (int v: adjacent) {
      if (trimmed.find(v) != trimmed.end()) {
        newadj.push_back(v);
      }
    }
    std::string adding;
    for (int to: newadj) {
      adding += std::to_string(to) + ","; 
    }
    if (adding.length() > 0) {
      adding.pop_back(); //remove the comma at the end
    }
    Writing << *itr << ',' << adding << '\n';
  }
  Writing.close();
  
  Writing2.close();
}
