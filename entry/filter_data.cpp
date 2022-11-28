#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include<sstream>

//finds the top 130K nodes and writes them to a file
bool compare(const std::pair<int,int> &a,const std::pair<int,int> &b) {
  return a.second > b.second;
}
int main() {
  static std::map<int, int> log;
  static std::map<int,std::string> titles;
  std::vector<std::pair<int,int>> filtered;
  std::ifstream infile("data/wikidata.txt"); //edge file
  std::ifstream infile2("data/enwiki-2013-names.csv"); //titles file
  std::string line;
  while (infile2) {
    std::getline(infile2, line);
    std::stringstream s_stream(line);
    size_t pos = line.find(',');
    std::cout << line << '\n';
    int idx = std::stoi(line.substr(0, pos));
    line.erase(0, pos + 1);
    titles[idx] = line;
    if (idx == 4206784) { //number of wikipedia pages
      break;
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
    // Writing << i.first << '\n';
    Writing << i.first << ',' << titles[i.first] << '\n';
  }
  Writing.close();
  std::cout << "SIZE OF FILTERED IS: " << filtered.size() << '\n';

}
