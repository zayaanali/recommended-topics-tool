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
/** related_topics_two_inputs.cpp
 * takes two command line arguments of the indexes of two different Wikipedia pages
 * returns related topics to the given input by tracing back the shortest path between them and picking the node with the median betweenness centrality
 * when there are multiple predecessors to choose from.
*/
std::map<int,double> betweenness;
bool compareB(const int &a,const int &b) {
  return betweenness[a] < betweenness[b];
}

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cout << "You did not enter enough arguments. Please enter the indexes of two wikipedia pages" << '\n';
    return 0;
  }
  if (argc > 3) {
    std::cout << "You entered too many arguments. Please enter the indexes of two wikipedia pages" << '\n';
    return 0;
  }
  int topic1 = std::stoi(argv[1]); //741034 -> piano
  int topic2 = std::stoi(argv[2]); //605008 -> France
  Graph graph("../data/finaladj.txt", 15470);
  betweenness = load_betweenness("../data/betweenness.txt", graph, 15470);
  std::map<int,std::string> titles = load_titles("../data/finaltitles.txt", graph, 15470);
  std::map<int, std::vector<int>> predecessor = graph.brandes_predecessor(topic1);
  int current = topic2;
  std::vector<int> street;
  while (current != topic1) {
    std::vector<int> options = predecessor[current];
    std::sort(options.begin(), options.end(), compareB);
    street.push_back(options[options.size() / 2]); //the full path
    current = options[options.size() / 2]; // picks the node with the middle betweenness centrality if there are multiple predecessors
  }
  std::cout << "~~~~~" << '\n';
  for (int stop: street) {
    std::cout << titles[stop] << '\n';
  }
  
  
}
