#include "BestFirstSearch.h"

#include "CityGraph.h"
#include <queue>
#include <functional>
#include <vector>
#include <iostream>

using std::vector;
using std::string;
using std::unordered_map;
using std::priority_queue;

vector<string> bestFirstSearch(const CityGraph& graph, const string& start, const string& goal, double& totalDistance) {
    // Convert to HeuristicCity graph if not already
    unordered_map<string, HeuristicCity> heuristicGraph;
    for (const auto& pair : graph) {
        const auto& city = pair.second;
        heuristicGraph[pair.first] = HeuristicCity(city.name, city.latitude, city.longitude, 0.0);
        std::cout << heuristicGraph[pair.first].adjacents.size() << std::endl;
    }

    // Assume goal city coordinates are known and update heuristics
    const HeuristicCity& goalCity = heuristicGraph.at(goal);
    for (auto& pair : heuristicGraph) {
        pair.second.updateHeuristic(goalCity);
    }

    for (auto& pair : graph) {
        heuristicGraph[pair.first].adjacents = pair.second.adjacents;
    }

    auto compare = [&](const string& a, const string& b) {
        return heuristicGraph.at(a).heuristic > heuristicGraph.at(b).heuristic;
        };
    priority_queue<string, vector<string>, decltype(compare)> frontier(compare);

    unordered_map<string, string> cameFrom;
    frontier.push(start);
    cameFrom[start] = "";

    while (!frontier.empty()) {
        string current = frontier.top();
        frontier.pop();

        if (current == goal) {
            vector<string> path;
            for (string at = goal; at != ""; at = cameFrom[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
        } else {
            std::cout << heuristicGraph.at(current).adjacents.size() << std::endl;
            for (const string& next : heuristicGraph.at(current).adjacents) {
                if (!cameFrom.count(next)) {
                    frontier.push(next);
                    cameFrom[next] = current;
                }
            }
        }
    }

    return {}; // If no path found
}