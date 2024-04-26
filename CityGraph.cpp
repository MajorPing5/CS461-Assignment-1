// CityGraph.cpp
#include "CityGraph.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

vector<string> breadthFirstSearch(const CityGraph& graph, const string& start, const string& goal, double& totalDistance) {
    queue<string> queue;
    unordered_map<string, string> cameFrom; // Track the path
    unordered_map<string, bool> visited; // Notes nodes already taken

    // Initialize BFS
    queue.push(start);
    visited[start] = true;
    cameFrom[start] = ""; // Start has no predecessor
    totalDistance = 0.0;

    // BFS Algorithm
    while (!queue.empty()) {
        string current = queue.front();
        queue.pop();

        // Goal check
        if (current == goal) {
            vector<string> path;
            string temp = goal;
            string at = goal;
            while (at != "") {
                path.push_back(at);
                string predecessor = cameFrom[at];

                // Error upon execution here: out of range
                if (predecessor != "" && predecessor != start) {
                    // Check if the predecessor exists in the graph before trying to access it
                    if (graph.find(at) != graph.end() && graph.find(predecessor) != graph.end()) {
                        totalDistance += graph.at(at).distanceTo(graph.at(predecessor));
                    }
                }
                // End of error execution

                at = predecessor; // Move to the predecessor for the next iteration
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Neighbor Exploration
        if (graph.find(current) != graph.end()) {
            for (const string& next : graph.at(current).adjacents) {
                if (!visited[next]) {
                    queue.push(next);
                    visited[next] = true;
                    cameFrom[next] = current;
                }
            }
        }
    }

    return {}; // Return empty path if goal is not reachable
}

vector<string> depthFirstSearch(const CityGraph& graph, const string& start, const string& goal, double& totalDistance) {
    stack<string> stack;
    unordered_map<string, string> cameFrom; // For path reconstruction
    unordered_map<string, double> distanceFromStart;
    unordered_set<string> visited; // Tracks visited nodes
    totalDistance = 0.0;

    // Initialize DFS
    stack.push(start);
    cameFrom[start] = "";
    distanceFromStart[start] = 0.0;


    //DFS Algorithm
    while (!stack.empty()) {
        string current = stack.top();
        stack.pop();

        // Mark as visited
        visited.insert(current);

        // Goal check
        if (current == goal) {
            vector<string> path;
            string at = goal;

            // Reconstruct path and calculate total distance using the enhanced snippet
            while (at != "") {
                path.push_back(at);
                string predecessor = cameFrom[at];

                // Ensure valid graph access and calculate distance
                if (predecessor != "" && predecessor != start) {
                    if (graph.find(at) != graph.end() && graph.find(predecessor) != graph.end()) {
                        totalDistance += graph.at(at).distanceTo(graph.at(predecessor));
                    }
                }

                at = predecessor; // Move to the predecessor for the next iteration
            }

            reverse(path.begin(), path.end());
            return path; // Return the path found
        }

        // Explore neighbors
        for (const string& next : graph.at(current).adjacents) {
            if (visited.find(next) == visited.end()) {
                stack.push(next);
                if (cameFrom.find(next) == cameFrom.end()) { // Avoid overwriting cameFrom if already set
                    cameFrom[next] = current;
                }
            }
        }
    }

    return {}; // Return empty path if goal is not reachable
}

bool DLS(const CityGraph& graph, const std::string& src, const std::string& goal, int depth, std::vector<std::string>& path) {
    if (src == goal) {
        path.push_back(src);
        return true;
    }
    if (depth <= 0) return false;

    auto it = graph.find(src);
    if (it == graph.end()) return false;

    for (const std::string& adj : it->second.adjacents) {
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