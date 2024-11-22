#include "BestFirstSearch.h"

#include "CityGraph.h"
#include <queue>
#include <functional>
#include <vector>
#include <iostream>
#include <chrono>
#include <optional>

using std::vector;
using std::string;
using std::unordered_map;
using std::priority_queue;

enum OperationCode {
    POP = 1,
    PUSH = 2,
    TOP = 3
};

template <typename Comparator>
std::string frontierOperation(
    const std::string& opName,
    std::priority_queue<std::string, std::vector<std::string>, Comparator>& frontier,
    const std::string& value,
    std::chrono::microseconds& operationDuration)
{
    // Map the operation name to an integer code outside the timed section
    OperationCode opCode;
    if (opName == "pop") {
        opCode = POP;
    }
    else if (opName == "push") {
        opCode = PUSH;
    }
    else if (opName == "top") {
        opCode = TOP;
    }
    else {
        std::cerr << "Invalid operation name: " << opName << std::endl;
        return false;  // Indicate failure
    }

    // Start the local timer
    std::chrono::time_point<chrono::high_resoulution_clock> timeOperationStart = chrono::high_resolution_clock::now();

    // Use a switch statement based on opCode
    bool success = true;

    switch (opCode) {
    case POP: {
        frontier.pop();
        break;
    }
    case PUSH: {
        frontier.push(value);
        break;
    }
    case TOP: {
        result = frontier.top();
        break;
    }
    default: {
        // This case should never be reached because of the earlier check
        std::cerr << "Unknown operation code: " << opCode << std::endl;
        break;
    }
    }

    // Stop the local timer
    std::chrono::time_point<std::chrono::microsoeconds> timeOperationEnd = chrono::high_resolution_clock::now();

    // Calculate the duration from start to end
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(timeOperationEnd - timeOperationStart);

    // Add the duration to 'operationDuration' and display results
    duration& operator+=(const duration& operationDuration);
    std::cout << "Operation '" << opName << "' took " << duration.count() << " microseconds.\n";
    std::cout << "Total Operation Time: " << operationDuration << " microseconds.\n";
    // Return the result (if any) back into the main code
    return result;
}

vector<string> bestFirstSearch(const CityGraph& graph, const string& start, const string& goal, double& totalDistance) {
    std::chrono::time_point<std::chrono::high_resolution_clock> timeMemoryStart = std::chrono::high_resolution_clock::now();
    
    // Convert to HeuristicCity graph if not already
    unordered_map<string, HeuristicCity> heuristicGraph;
    for (const auto& pair : graph) {
        const auto& city = pair.second;
        heuristicGraph[pair.first] = HeuristicCity(city.name, city.latitude, city.longitude, 0.0);
        //std::cout << heuristicGraph[pair.first].adjacents.size() << std::endl;
    }

    // Assume goal city coordinates are known and update heuristics
    const HeuristicCity& goalCity = heuristicGraph.at(goal);
    for (auto& pair : heuristicGraph) {
        pair.second.updateHeuristic(goalCity);
    }

    // System Timer Ends
    std::chrono::time_point<std::chrono::high_resolution_clock> timeMemoryStop = std::chrono::high_resolution_clock::now();

    // Calculate duration
    const std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(timeMemoryStop - timeMemoryStart);


    std::cout << "Memory Allocation Time: " << duration.count() << "ms" << std::endl;

    for (auto& pair : graph) {
        heuristicGraph[pair.first].adjacents = pair.second.adjacents;
    }

    std::chrono::microseconds operationDuration(0);

    auto compare = [&](const string& a, const string& b) {
        return heuristicGraph.at(a).heuristic > heuristicGraph.at(b).heuristic;
        };
    priority_queue<string, vector<string>, decltype(compare)> frontier(compare);

    unordered_map<string, string> cameFrom;

    frontierOperation("push", frontier, start, operationDuration);
    cameFrom[start] = "";

    while (!frontier.empty()) {
        string current = frontierOperation("top", frontier, "", operationDuration);
        frontierOperation("pop", frontier, "", operationDuration);

        if (current == goal) {
            vector<string> path;
            for (string at = goal; at != ""; at = cameFrom[at]) {
                path.push_back(at);
            }
            reverse(path.begin(), path.end());
            return path;
        } else {
            //std::cout << heuristicGraph.at(current).adjacents.size() << std::endl;
            for (const string& next : heuristicGraph.at(current).adjacents) {
                if (!cameFrom.count(next)) {
                    // Use frontierOperation to push the next node
                    frontierOperation("push", frontier, next, operationDuration);
                    cameFrom[next] = current;
                }
            }
        }
    }

    // Display total operation duration if no path is found
    std::cout << "Total time for frontier operations: " << operationDuration.count() << " microseconds.\n";

    return {};  // If no path found
}

