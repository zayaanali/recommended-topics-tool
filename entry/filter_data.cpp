#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include<sstream>

/** filter_data.cpp
 * first step in data parsing pipeline
 * finds the top 130K nodes (nodes with the highest in-degree) from the downloaded data set of Wikipedia pages (Stanford Large Network Dataset Collection) and writes them to a file
 * writes output to "filteredwiki.txt"
 * each line in the output file has the node index followed by its title
 * output is sorted by highest in-degree (line 1 will be the node with the most links to it)
 * all nodes with more than 100 links to it are included in the initial filter.
*/
bool compare(const std::pair<int,int> &a,const std::pair<int,int> &b) {
  return a.second > b.second;
}
int main() {
  static std::map<int, int> log;
  static std::map<int,std::string> titles;
  std::vector<std::pair<int,int>> filtered;
  std::ifstream infile("../data/wikidata.txt"); //edge file
  std::ifstream infile2("../data/enwiki-2013-names.csv"); //titles file
  std::string line;
  int idx = 0;
  while (infile2) {
    if (idx == 4206784) { //number of lines in file
      break;
    }
    std::getline(infile2, line);
    std::stringstream s_stream(line);
    size_t pos = line.find(',');
    std::cout << line << '\n';
    int nodeID = std::stoi(line.substr(0, pos));
    line.erase(0, pos + 1);
    titles[nodeID] = line;
    idx++;
    
  }
  int from, to;
  while (infile >> from >> to) {
    log[to]++;
  }
  for (auto i = log.begin(); i != log.end(); i++) {
    if (i->second > 100) {
      filtered.push_back(std::make_pair(i->first, i->second));
      std::cout << i->first << ' ' << i->second << '\n';
    }
  }
  std::sort(filtered.begin(), filtered.end(), compare);
  std::ofstream Writing("../data/filteredwiki.txt");
  for (auto i: filtered) {
    // Writing << i.first << '\n';
    if (i.first == 3165770) {
      continue; //Exclude "List of sovereign states"
    }
    Writing << i.first << ',' << titles[i.first] << '\n';
  }
  Writing.close();
  std::cout << "SIZE OF FILTERED IS: " << filtered.size() << '\n';
  
}
