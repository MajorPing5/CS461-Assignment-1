#include "IDDFS.h"
#include <vector>

using namespace std;

bool DLS(const CityGraph& graph, const string& src, const string& goal, int depth, vector<string>& path) {
    if (src == goal) {
        path.push_back(src);
        return true;
    }
    if (depth <= 0) return false;

    auto it = graph.find(src);
    if (it == graph.end()) return false;

    for (const string& adj : it->second.adjacents) {
        if (DLS(graph, adj, goal, depth - 1, path)) {
            path.push_back(src);
            return true;
        }
    }
    return false;
}

// IDDFS implementation using existing graph structure
vector<string> IDDFS(const CityGraph& graph, const string& start, const string& goal) {
    for (int depth = 0; depth < INT_MAX; ++depth) {
        vector<string> path;
        if (DLS(graph, start, goal, depth, path)) {
            reverse(path.begin(), path.end());
            return path;
        }
    }
    return {};
}