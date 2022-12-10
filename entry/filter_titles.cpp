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

/** filter_titles.cpp
  * third step in data parsing pipeline
  * filters the titles CSV file for each index based on "filteredadj.txt" (generated from "filter_data.cpp")
  * creates a new titles csv file with only the nodes that were kept after filtering
  * used to generate "filteredtitles.txt"
*/
int main() {
  static std::map<int, std::vector<int>> adj;
  std::unordered_set<int> idxs;
  static std::map<int,std::string> titles;
  std::ifstream infile("../data/filteredadj.txt");
  
  //load adj list
  std::string line;
  int idx = 0;
  while (infile) {
    if (idx == 23757) { //length of the "filteredadj.txt" file
      break;
    }
    std::getline(infile, line);
    std::vector<int> parts;
    SplitString(line, ',', parts);
    int nodeID = parts[0];
    idxs.insert(nodeID);
    parts.erase(parts.begin());
    adj[nodeID] = parts;
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
  std::ofstream Writing("../data/filteredtitles.txt");
  for (auto it = titles.begin(); it != titles.end(); it++) {
    Writing << it->first << ',' << it->second << '\n';
  }
  Writing.close();

}
