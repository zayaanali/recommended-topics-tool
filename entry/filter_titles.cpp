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

int main() {
  static std::map<int, std::vector<int>> adj;
  std::unordered_set<int> idxs;
  static std::map<int,std::string> titles;
  std::ifstream infile("../data/filterededges.txt"); //edge file
  
  //load adj list
  std::string line;
  int idx = 0;
  while (infile) {
    std::getline(infile, line);
    std::vector<int> parts;
    SplitString(line, ',', parts);
    int nodeID = parts[0];
    idxs.insert(nodeID);
    parts.erase(parts.begin());
    adj[nodeID] = parts;
    if (idx == 131511) { //number of pages with more than 100 links to it
      break;
    }
    idx++;
  }

  //load titles
  std::ifstream infile2("../data/enwiki-2013-names.csv"); //titles file
  while (infile2) {
    std::getline(infile2, line);
    std::stringstream s_stream(line);
    size_t pos = line.find(',');
    int idx = std::stoi(line.substr(0, pos));
    line.erase(0, pos + 1);
    if (idxs.find(idx) != idxs.end()) {
      titles[idx] = line;
    }
    if (idx == 4206784) { //number of wikipedia pages
      break;
    }
  }
  std::ofstream Writing("../data/reducedtitles.txt");
  for (auto it = titles.begin(); it != titles.end(); it++) {
    Writing << it->first << ',' << it->second << '\n';
  }
  Writing.close();

}
