#include "DepthFirstSearch.h"
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

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