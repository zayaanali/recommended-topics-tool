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
  static std::map<int,std::string> titles;
  Graph graph("../data/finaladj.txt", 15470);
  titles = load_titles("../data/finaltitles.txt", graph, 15470);
  std::map<int, double> betweenness = graph.brandes();
  std::ofstream Writing("../data/betweenness.txt");
  for (auto i: betweenness) {
    Writing << i.first << ',' << i.second << '\n';
  }
  Writing.close();
}
