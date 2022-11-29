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
//us_demo.cpp, CAN SEARCH SHORTEST PATH FROM ANY NODE TO US, ALSO TRIMS DOWN NODES USING BFS
void BFS(std::map<int, std::vector<int>>& adj, std::map<int, bool>& visited, std::unordered_set<int>& nodes, std::map<int, int>& predecessor, int start, int bound) {
  //normal bfs if bound is less than 0, otherwise runs a certain number of steps away from the starting node
  //returns nodes visited
  std::queue<int> q;
  std::map<int, int> distance;
  distance[start] = 0;
  visited[start] = true;
  q.push(start);
  bool finished = false;
  while (!q.empty() && !finished) {
    int v = q.front();
    nodes.insert(v);
    q.pop();
    for (int neighbor: adj[v]) {
      if (!visited[neighbor]) {
        distance[neighbor] = distance[v] + 1;
        if (bound > 0 && distance[neighbor] > bound) {
          finished = true;
        } else {
          visited[neighbor] = true;
          if (start == 2038044) {
            predecessor[neighbor] = v;
            //predecessor is only a test for United States as the root
          }
          
          q.push(neighbor);
        }
        
      }
    }
  }
}
int main() {
  static std::map<int, std::vector<int>> adj;
  std::unordered_set<int> idxs;
  static std::map<int,std::string> titles;
  std::ifstream infile("../data/finaladj.txt"); //edge file
  
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
    if (idx == 42196) { //number of pages with more than 100 links to it
      break;
    }
    idx++;
  }

  //load titles

  std::ifstream infile2("../data/finaltitles.txt"); //titles file
  idx = 0;
  while (infile2) {
    idx++;
    std::getline(infile2, line);
    std::stringstream s_stream(line);
    size_t pos = line.find(',');
    int id = std::stoi(line.substr(0, pos));
    line.erase(0, pos + 1);
    if (idxs.find(id) != idxs.end()) {
      titles[id] = line;
    }
    if (idx == 42196) { //number of titles
      break;
    }
  }
  //BFS
  static std::map<int, bool> visited;
  static std::map<int, int> predecessor;
  for (auto itr = idxs.begin(); itr != idxs.end(); itr++) {
    visited[*itr] = false;
  }
  std::vector<int> topten = {2038044, 3846441};
  std::unordered_set<int> trimmed;

  for (int id: topten) {
    BFS(adj, visited, trimmed, predecessor, id, 3);
    for (auto itr = idxs.begin(); itr != idxs.end(); itr++) {
      visited[*itr] = false;
    } 
  }
  while (true) {
    std::cout << "Search: ";
    int input;
    std::cin >> input;
    if (input == -1) {
      break;
    }
    int current = input;
    int steps = 0;
    while (current != 2038044 && steps < 5) {
      std::cout << titles[predecessor[current]] << '\n';
      current = predecessor[current];
      steps++;
    }
  }
}
