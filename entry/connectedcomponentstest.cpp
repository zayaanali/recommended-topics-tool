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
/** brandes.cpp
 * Runs Brandes on the trimmed Wikipedia data set
 * Writes a CSV out to betweenness.txt where each line is of the form "node index","betweenness centrality"
*/
int main() {
  Graph graph("../data/finaladj.txt", 15470);
  std::map<int,std::string> titles = load_titles("../data/finaltitles.txt", graph, 15470);
  std::map<std::string,int> reverse_titles = load_titles_reverse("../data/finaltitles.txt", graph, 15470);
  std::map<int, std::vector<int>> sccs = graph.getSCCs();
  std::cout << sccs.size() << '\n';
  for (unsigned int i = 0; i < sccs.size(); i++) {
    std::cout << i << ": " << sccs[i].size() << '\n';
  }
}