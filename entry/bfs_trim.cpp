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
/** bfs_trim.cpp
  * fourth and final step in data parsing pipeline
  * Trims down the initially filtered 24K nodes to a single connected graph of around ~15K
  * Runs BFS_trim with 3 seeds. 
  * BFS will start at the 3 seeds ("US", "animal", and "food") and travel up to 2 steps away from the node
  * All nodes that are reached are added to the final set of nodes
  * Writes out the adjacency list of the trimmed, connected graph to "finaladj.txt"
  * Writes out the final CSV of title labels for each node index to "finaltitles.txt"
*/
int main() {
  static std::map<int,std::string> titles;
  std::unordered_set<int> trimmed;
  Graph graph("../data/filteredadj.txt", 23757);
  titles = load_titles("../data/filteredtitles.txt", graph, 23757);
  std::vector<int> topten = {2038044, 3846441, 423902}; //United States, Animal, Food (3 general topics)
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
