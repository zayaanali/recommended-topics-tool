#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_set>
#include<sstream>

/** filter_edges.cpp
 * second step in data parsing pipeline
 * creates and stores an adjacency list with only the top 24K nodes from the Wikipedia data set
 * Uses the edges file and the list of top 24K nodes from "filter_data.cpp" to create the adjacency list
 * writes out output to "filteredadj.txt" as a csv where each line has the index of the node followed by all the nodes it is adjacent to
*/
int main() {
  static std::map<int, std::vector<int>> full_adj;
  static std::map<int, std::vector<int>> cut_adj;
  std::unordered_set<int> trimmed;
  std::ifstream infile("../data/filteredwiki.txt");
  std::ifstream infile2("../data/wikidata.txt"); //edge file
  int from, to;
  while (infile2 >> from >> to) {
    full_adj[from].push_back(to);
  }
  std::string line;
  int idx = 0;
  while (infile) {
    if (idx == 23757) { //length of file
      break;
    }
    std::getline(infile, line);
    std::stringstream s_stream(line);
    size_t pos = line.find(',');
    int nodeID = std::stoi(line.substr(0, pos));
    trimmed.insert(nodeID);
    idx++;
  }
  std::ofstream Writing("../data/filteredadj.txt");
  //writes out adjacency list
  for (auto itr = trimmed.begin(); itr != trimmed.end(); itr++) {
    std::vector<int> adjacent = full_adj[*itr];
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
      adding.pop_back();
    }
    Writing << *itr << ',' << adding << '\n';
    cut_adj[*itr] = newadj;
  }
  Writing.close();
}
