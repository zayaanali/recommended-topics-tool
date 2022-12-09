#include "graph.h"
#include <stack>

using std::cout;
using std::vector;
using std::map;
using std::stack;
using std::endl;

/*
 * Pseudocode:
 * 1) DFS traversal in stack
 * 2) Find the transpose by reversing edges
 * 3) Pop nodes from stack and DFS transposed nodes
*/


void Graph::getSCCs() {
    
    

    graph_.clear();
    graph_[0] = {1};
    graph_[1] = {2};
    graph_[2] = {0,3};
    graph_[3] = {4};
    graph_[4] = {5};
    graph_[5] = {6};
    graph_[6] = {7,4};
    graph_[7] = {};


    // for (auto const& [key, val] : graph_) {
    //     std::cout << key << ": ";  
    //     for (auto it: val) {
    //         cout << it << " ";
    //     }
    //     cout << std::endl;
    // }
    
    int numComponents=0; // number of strongly connected components
    stack<int> s;
    map<int, vector<int>> SCCs; // adjacency list of SCCs
    visited_.resize(100, false); // resized to number of nodes in graph (prev graph_.size())

    // Get DFS traversal order
    for (size_t i=0; i<graph_.size(); i++) { // visit each node
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
    // cout << "Transpose" << endl;
    // for (auto const& [key, val] : transpose) {
    //     std::cout << key << ": ";  
    //     for (auto it: val) {
    //         cout << it << " ";
    //     }
    //     cout << std::endl;
    // }

    // reset visited array to false
    for (size_t i=0; i<100; i++)
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
    
    
    cout << "SCC" << endl;
    for (auto const& [key, val] : SCCs) {
        std::cout << key << ": ";  
        for (auto it: val) {
            cout << it << " ";
        }
        cout << std::endl;
    }
    cout << "Number of Components: " << numComponents << endl;
}

// DFS traversal order
void Graph::dfs_1(int v, stack<int> &s)  {

    // mark visited
    visited_[v]=true;
    //cout << v << " ";
    
    // continue DFS
    for (size_t i=0; i<graph_[v].size(); i++) {
        //cout << "HERE: " << graph_[v][i] << endl;
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
    for (size_t i=0; i<transpose[v].size(); i++) {
        if (!visited_[transpose[v][i]])
            dfs_2(transpose[v][i], SCCs, numComponents, transpose);
    }
}