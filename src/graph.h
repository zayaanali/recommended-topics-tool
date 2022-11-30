#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <string>
#include "utils.h"
#include <sstream>

class Graph {
    public:
        Graph(const std::string& filename);
        std::unordered_set<int> BFS_Trim(const std::vector<int>& seeds);
        void BFS(std::map<int, bool>& visited, std::unordered_set<int>& nodes, std::map<int, int>& predecessor, int start, int bound);
        std::map<int, int> shortest_paths(int start);
        friend std::map<int,std::string>& load_titles(const std::string& filename, const Graph& graph);
    private:
        std::map<int, std::vector<int>> graph_;
        std::unordered_set<int> idxs_;
};

std::map<int,std::string>& load_titles(const std::string& filename, const Graph& graph);