#include "IDDFS.h"
#include <vector>

using namespace std;

bool DLS(const CityGraph& graph, const string& src, const string& goal, int depth, vector<string>& path, double& totalDistance, double currentDistance = 0.0) {
    if (src == goal) {
        path.push_back(src);
        totalDistance = currentDistance;
        return true;
    }
    if (depth <= 0) return false;

    auto src_it = graph.find(src);
    if (src_it == graph.end()) return false;

    for (const string& adj : src_it->second.adjacents) {
        auto adj_it = graph.find(adj);
        if (adj_it == graph.end()) continue;

        double edgeDistance = src_it->second.distanceTo(adj_it->second);
        if (DLS(graph, adj, goal, depth - 1, path, totalDistance, currentDistance + edgeDistance)) {
            path.push_back(src);
            return true;
        }
    }
    return false;
}

// IDDFS implementation using existing graph structure
vector<string> IDDFS(const CityGraph& graph, const string& start, const string& goal, double& totalDistance) {
    for (int depth = 0; depth < INT_MAX; ++depth) {
        vector<string> path;
        if (DLS(graph, start, goal, depth, path, totalDistance)) {
            reverse(path.begin(), path.end());
            // totalDistance is already set by DLS
            return path;
        }
    }
    totalDistance = 0.0; // No path found, so set distance to 0
    return {};
}
