#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <string>
#include "utils.h"
#include <sstream>
#include <fstream>
#include <stack>


class Graph {
    public:
        Graph(const std::string& filename, int num);
        std::unordered_set<int> BFS_Trim(const std::vector<int>& seeds, int bound);
        void BFS(std::map<int, bool>& visited, std::unordered_set<int>& nodes, std::map<int, int>& predecessor, int start, int bound);
        std::vector<int> getAdjacent(int idx);
        std::map<int, int> shortest_paths(int start);
        friend std::map<int,std::string>& load_titles(const std::string& filename, const Graph& graph);
        
        //SCC
        void getSCCs();
        void dfs_1(int v, std::stack<int> &s);
        void dfs_2(int v, std::map<int, std::vector<int>> &SCCs, int &numComponents, std::map<int, std::vector<int>> &transpose);
    private:
        std::unordered_set<int> idxs_;
        // SCC
        std::map<int, std::vector<int>> graph_;
        std::vector<bool> visited_;
};

std::map<int,std::string>& load_titles(const std::string& filename, const Graph& graph);