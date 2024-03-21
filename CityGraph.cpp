// CityGraph.cpp
#include "CityGraph.h"
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>

using namespace std;
// Include other necessary standard library headers

// Implementations of your search algorithms

/*  Breath First Search - An algorithm that focuses on finding the neighboring nodes of all nodes at depth i
    before iterating by 1, visiting every child till the goal is found
    Parameters:
    @param graph    =   Full Graph given by coordinates.csv, constant variable
    @param start    =   User Inputted Variable, constant variable upon execution
    @param goal     =   User Inputted Variable, constant variable upon execution */
vector<string> breadthFirstSearch(const CityGraph& graph, const string& start, const string& goal) {
    queue<string> queue;
    unordered_map<string, string> cameFrom; // Track the path
    unordered_map<string, bool> visited;

    // Initialize BFS
    queue.push(start);
    visited[start] = true;
    cameFrom[start] = ""; // Start has no predecessor

    // BFS Algorithm
    while (!queue.empty()) {
        string current = queue.front();
        queue.pop();

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
        for (const string& next : graph.at(current)) {
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
        for (const string& next : graph.at(current)) {
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
