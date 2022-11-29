#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_set>
#include<sstream>

//creates and stores an adjacency list with only the top 130K nodes
int main() {
  static std::map<int, std::vector<int>> full_adj;
  static std::map<int, std::vector<int>> cut_adj;
  std::unordered_set<int> trimmed;
  std::ifstream infile("../filteredwiki.txt");
  std::ifstream infile2("../data/wikidata.txt"); //edge file
  int from, to;
  while (infile2 >> from >> to) {
    full_adj[from].push_back(to);
  }
  std::string line;
  while (infile) {
    std::getline(infile, line);
    std::stringstream s_stream(line);
    size_t pos = line.find(',');
    std::cout << line << '\n';
    int idx = std::stoi(line.substr(0, pos));
    trimmed.insert(idx);
    if (idx == 131511) { //number of pages with more than 100 links to it
      break;
    }
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
