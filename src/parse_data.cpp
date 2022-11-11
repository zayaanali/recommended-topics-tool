#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include<sstream>

bool compare(const std::pair<int,int> &a,const std::pair<int,int> &b) {
  return a.second > b.second;
}
int main() {
  static std::map<int, int> log;
  static std::map<int,std::string> titles;
  std::vector<std::pair<int,int>> filtered;
  std::ifstream infile("Downloads/wikidata.txt");
  std::ifstream infile2("Downloads/enwiki-2013-names.csv");
  std::string line;
  while (infile2 >> line) {
    std::stringstream s_stream(line);
    while(s_stream.good()) {
     std::string part;
     std::getline(s_stream, part, ','); //get first string delimited by comma
     result.push_back(substr);
    }
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
  std::ofstream Writing("filteredwiki.txt");
  for (auto i: filtered) {
    Writing << i.first << '\n';
  }
  Writing.close();
  std::cout << "SIZE OF FILTERED IS: " << filtered.size() << '\n';

}
