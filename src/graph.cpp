#include "graph.h"
#include <iostream>
Graph::Graph(const std::string& filename, int num) {
    std::ifstream infile(filename); //edge file
    //load adj list
    std::string line;
    int idx = 0;
    while (infile) {
        std::getline(infile, line);
        std::vector<int> parts;
        SplitString(line, ',', parts);
        int nodeID = parts[0];
        idxs_.insert(nodeID);
        parts.erase(parts.begin());
        graph_[nodeID] = parts;
        if (idx == num) { //number of pages with more than 100 links to it
            break;
        }
        idx++;
    }
}   

std::unordered_set<int> Graph::BFS_Trim(const std::vector<int>& seeds, int bound) {
    static std::map<int, bool> visited;
    static std::map<int, int> predecessor;
    for (auto itr = idxs_.begin(); itr != idxs_.end(); itr++) {
        visited[*itr] = false;
    }
    std::unordered_set<int> trimmed;
    for (int id: seeds) {
        BFS(visited, trimmed, predecessor, id, bound);
        for (auto itr = idxs_.begin(); itr != idxs_.end(); itr++) {
            visited[*itr] = false;
        } 
    }
    return trimmed;
}
void Graph::BFS(std::map<int, bool>& visited, std::unordered_set<int>& nodes, std::map<int, int>& predecessor, int start, int bound) {
    //normal bfs if bound is less than 0, otherwise runs a certain number of steps away from the starting node
  //returns nodes visited
  std::queue<int> q;
  std::map<int, int> distance;
  distance[start] = 0;
  visited[start] = true;
  q.push(start);
  while (!q.empty()) {
    int v = q.front();
    if (bound > 0 && distance[v] > bound) {
        break;
    }
    nodes.insert(v);
    q.pop();
    for (int neighbor: graph_[v]) {
      if (!visited[neighbor]) {
        distance[neighbor] = distance[v] + 1;
        visited[neighbor] = true;
        predecessor[neighbor] = v;
        q.push(neighbor);
        
      }
    }
  }
}

std::vector<int> Graph::getAdjacent(int idx) {
    return graph_[idx];
}
std::map<int, int> Graph::shortest_paths(int start) {
  static std::map<int, bool> visited;
  static std::map<int, int> predecessor;
  for (auto itr = idxs_.begin(); itr != idxs_.end(); itr++) {
    visited[*itr] = false;
  }

  std::queue<int> q;
  std::map<int, int> distance;

  distance[start] = 0;
  visited[start] = true;
  q.push(start);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int neighbor: graph_[v]) {
      if (!visited[neighbor]) {
        distance[neighbor] = distance[v] + 1;
        visited[neighbor] = true;
        predecessor[neighbor] = v;
        q.push(neighbor);
      }
    }
  }
  return predecessor;
}
std::map<int,std::string>& load_titles(const std::string& filename, const Graph& graph) {
    static std::map<int,std::string> titles;
    std::ifstream infile2(filename); //titles file
    std::string line;
    int idx = 0;
    while (infile2) {
        idx++;
        std::getline(infile2, line);
        std::stringstream s_stream(line);
        size_t pos = line.find(',');
        int id = std::stoi(line.substr(0, pos));
        line.erase(0, pos + 1);
        if (graph.idxs_.find(id) != graph.idxs_.end()) {
            titles[id] = line;
        }
        if (idx == 42196) { //number of titles
            break;
        }
    }
    return titles;
}
