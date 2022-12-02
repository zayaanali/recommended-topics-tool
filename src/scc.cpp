#include "graph.h"
#include <stack>

using std::cout;
using std::vector;
using std::map;
using std::stack;

/*
 * Pseudocode:
 * 1) DFS traversal in stack
 * 2) Find the transpose by reversing edges
 * 3) Pop nodes from stack and DFS transposed nodes
*/


void Graph::getSCCs() {
    
    int numComponents=0; // number of strongly connected components
    stack<int> s;
    map<int, vector<int>> SCCs; // adjacency list of SCCs
    visited_.resize(graph_.size(), false);

    // Get DFS traversal order
    for (size_t i=0; i<graph_.size(); i++) {
        if (!visited_[i])
            dfs_1(i, s);
    }

    // create transpose of graph
    map<int, vector<int>> transpose;
    for (size_t i=0; i<graph_.size(); i++) {
        for (size_t j=0; j<graph_[i].size(); j++) {
            int src=graph_[i][j];
            int dest=i;
            
            transpose[src].push_back(dest);
        }
    }

    // reset visited array to false
    for (size_t i=0; i<graph_.size(); i++)
        visited_[i]=false;

    // pop nodes from DFS stack and perform dfs again
    while (!s.empty()) {
        int v = s.top();
        s.pop();

        if (!visited_[v]) {
            cout << "Component " << numComponents << ": ";
            dfs_2(v, SCCs, numComponents, transpose); // prints all the CCs
            numComponents++;
            cout << "\n";
        }
    }

}



// DFS traversal order
void Graph::dfs_1(int v, stack<int> &s)  {

    // mark visited
    visited_[v]=true;
    
    // continue DFS
    for (size_t i=0; i<graph_[v].size(); i++) {
        if (!visited_[graph_[v][i]])
            dfs_1(graph_[v][i], s);
    }

    // record traversal order
    s.push(v);
}

// DFS traversal order
void Graph::dfs_2(int v, map<int, vector<int>> &SCCs,  int &numComponents, map<int, vector<int>> &transpose) {
    cout << v << " ";
    SCCs[numComponents].push_back(v); // add connected component
    visited_[v]=true;
    
    // continue DFS on transposed graph
    for (size_t i=0; i<graph_[v].size(); i++) {
        if (!visited_[transpose[v][i]])
            dfs_2(transpose[v][i], SCCs, numComponents, transpose);
    }
}


