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

  Graph graph("../data/finaladj.txt", 15470);
  std::map<int,std::string> titles = load_titles("../data/finaltitles.txt", graph, 15470);
  std::map<std::string,int> reverse_titles = load_titles_reverse("../data/finaltitles.txt", graph, 15470);

  if (reverse_titles.find(argv[1]) == reverse_titles.end()) {
    std::cout << "The first argument is not a valid Wikipedia page title. Please try again." << '\n';
    return 0;
  }
  if (reverse_titles.find(argv[2]) == reverse_titles.end()) {
    std::cout << "The second argument is not a valid Wikipedia page title. Please try again." << '\n';
    return 0;
  }
  int topic1 = reverse_titles[argv[1]]; //741034 -> piano
  int topic2 = reverse_titles[argv[2]]; //605008 -> France
  betweenness = load_betweenness("../data/betweenness.txt", graph, 15470);
  
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
