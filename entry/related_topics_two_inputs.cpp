#include <map>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <unordered_set>
#include<sstream>
#include<cmath>
#include <queue>
#include "utils.h"
#include "graph.h"
/** related_topics_two_inputs.cpp
 * takes two command line arguments of the indexes of two different Wikipedia pages
 * returns related topics to the given input by tracing back the shortest path between them and picking the node with the median betweenness centrality
 * when there are multiple predecessors to choose from.
*/
std::map<int,double> betweenness;
double closest = 0;
bool compareB(const int &a,const int &b) {
  return betweenness[a] < betweenness[b];
}
bool closeB(const int &a,const int &b) {
  return std::abs(betweenness[a] - closest) < std::abs(betweenness[b] - closest);
}
int main(int argc, char** argv) {

  //check input
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

  //convert strings to node indexes
  int topic1 = reverse_titles[argv[1]]; 
  int topic2 = reverse_titles[argv[2]]; 
  betweenness = load_betweenness("../data/betweenness.txt", graph, 15470);
  
  //find shortest paths to topic 1
  std::map<int, std::vector<int>> predecessor = graph.brandes_predecessor(topic1);
  int current = topic2;

  std::vector<std::vector<int>> street;
  while (current != topic1) {
    std::vector<int> options = predecessor[current];
    if (options.size() == 0) {
      break;
    }
    std::sort(options.begin(), options.end(), compareB);
    std::vector<int> collection;
    if (options[options.size() / 2] != topic1) {
      unsigned int median = options.size() / 2;
      collection.push_back(options[median]); //pushing back the 3 predecessors with the most median betweenness centrality scores to a vector with the full path
      if (median + 1 < options.size()) {
        collection.push_back(options[median + 1]);
      }
      if (median != 0) { //can't use -1 since median will overflow
        collection.push_back(options[median - 1]);
      }
    }
    current = options[options.size() / 2]; // picks the node with the middle betweenness centrality if there are multiple predecessors
    if (collection.size() > 0) {
      street.push_back(collection);
    }
  }
  std::cout << "~~~~~" << '\n';
  if (street.size() == 0) {
    closest = betweenness[topic2];
    std::vector<int> neighbors = graph.getAdjacent(topic1);
    std::sort(neighbors.begin(), neighbors.end(), closeB);
    std::cout << "Direct link exists, finding a neighbor of " << titles[topic1] << " similar to " << titles[topic2] << '\n';
    std::cout << titles[neighbors[1]] << '\n';
  } else {
    for (int stop: street[street.size() / 2]) { //goes to the middle group of predecessors on the path, should be most related to both topics
    std::cout << titles[stop] << '\n';
    }
  }
  std::cout << "~~~~~" << '\n';
}
