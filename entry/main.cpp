#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_set>
#include<sstream>
//BFS FILE
int main() {
  static std::map<int, std::vector<int>> adj;
  std::ifstream infile("../data/filterededges.txt"); //edge file
  //TODO Load the graph from filterededges.txt (run filter_data and filter_edges)
  std::string line;
  while (infile) {
    std::getline(infile, line);
    
    if (idx == 131511) { //number of pages with more than 100 links to it
      break;
    }
  }
}
