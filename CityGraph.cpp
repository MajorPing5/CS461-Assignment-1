// CityGraph.cpp
#include "CityGraph.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <string>

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
            for (string at = goal; at != ""; at = cameFrom[at]) {
                path.push_back(at);
                
                // Error upon execution here: out of range
                if (cameFrom[at] != start) {
                    totalDistance += graph.at(at).distanceTo(graph.at(cameFrom[at]));
                }
                // End of error execution
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Neighbor Exploration
        for (const string& next : graph.at(current).adjacents) {
            if (!visited[next]) {
                queue.push(next);
                visited[next] = true;
                cameFrom[next] = current;
            }
        }
    }

    return {}; // Return empty path if goal is not reachable
}

vector<string> depthFirstSearch(const CityGraph& graph, const string& start, const string& goal) {
    stack<string> stack;
    unordered_map<string, string> cameFrom; // For path reconstruction
    unordered_set<string> visited; // Tracks visited nodes

    // Initialize DFS
    stack.push(start);
    cameFrom[start] = "";

    //DFS Algorithm
    while (!stack.empty()) {
        string current = stack.top();
        stack.pop();

        // Mark as visited
        visited.insert(current);

        // Goal check
        if (current == goal) {
            vector<string> path;
            for (string at = goal; at != ""; at = cameFrom[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
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
