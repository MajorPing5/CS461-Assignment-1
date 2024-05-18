#include "BreadthFirstSearch.h"
#include <vector>
#include <queue>

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
                if (predecessor != "") {
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