#include "CityGraph.h"      // Assuming this file contains City definitions and graph parsing functions
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "IDDFS.h"
#include "BestFirstSearch.h"
#include "AStarSearch.h"    // If you have implemented A* Search
#include <iostream>
#include <cassert>
#include <vector>
#include <string>

using namespace std;

// Function to run the unit tests
void runUnitTests(const CityGraph& graph) {
    cout << "Running Unit Tests..." << endl;

    // Test Cases: Add test cases based on your current dataset
    // Format: {start, goal, expected_path, expected_distance}
    struct TestCase {
        string start;
        string goal;
        vector<string> expectedPath;
        double expectedDistance;
    };

    // Example Test Cases - Derived from provided adjacencies and coordinates
    vector<TestCase> testCases = {
        // Simple tests for adjacent nodes
        {"Wichita", "Leon", {"Wichita", "Leon"}, 0.792848},  // Example distance to adjust later
        {"Newton", "McPherson", {"Newton", "McPherson"}, 0.428951}, // Directly connected cities
        {"South_Haven", "Bluff_City", {"South_Haven", "Bluff_City"}, 0.474844},

        // Longer paths - ensure these align with your graph data
        {"Wichita", "Topeka", {"Wichita", "Leon", "Andover", "Newton", "McPherson", "Marion", "Manhattan", "Topeka"}, 3.70337},
        {"Anthony", "Hillsboro", {"Anthony", "Bluff_City", "Kiowa", "Coldwater", "Pratt", "Hutchinson", "McPherson", "Hillsboro"}, 4.2296}, // Example

        // Test for node to itself
        {"Topeka", "Topeka", {"Topeka"}, 0.0} // Path to itself
    };

    // Test BFS
    /*cout << "Testing Breadth-First Search..." << endl;
    for (const auto& testCase : testCases) {
        double totalDistance = 0.0;
        vector<string> resultPath = breadthFirstSearch(graph, testCase.start, testCase.goal, totalDistance);
        assert(resultPath == testCase.expectedPath && "BFS path did not match expected result.");
        assert(abs(totalDistance - testCase.expectedDistance) < 0.001 && "BFS distance did not match expected result.");
        cout << "BFS Test Passed for: " << testCase.start << " -> " << testCase.goal << endl;*/
    }

    // Test DFS
    /*cout << "Testing Depth-First Search..." << endl;
    for (const auto& testCase : testCases) {
        double totalDistance = 0.0;
        vector<string> resultPath = depthFirstSearch(graph, testCase.start, testCase.goal, totalDistance);
        assert(resultPath == testCase.expectedPath && "DFS path did not match expected result.");
        assert(abs(totalDistance - testCase.expectedDistance) < 0.001 && "DFS distance did not match expected result.");
        cout << "DFS Test Passed for: " << testCase.start << " -> " << testCase.goal << endl;*/
    }

    // Test IDDFS
    /*cout << "Testing Iterative Deepening Depth First Search..." << endl;
    for (const auto& testCase : testCases) {
        double totalDistance = 0.0;
        vector<string> resultPath = IDDFS(graph, testCase.start, testCase.goal, totalDistance);
        assert(resultPath == testCase.expectedPath && "IDDFS path did not match expected result.");
        assert(abs(totalDistance - testCase.expectedDistance) < 0.001 && "IDDFS distance did not match expected result.");
        cout << "IDDFS Test Passed for: " << testCase.start << " -> " << testCase.goal << endl;*/
    }

    // Test Best-First Search
    cout << "Testing Best-First Search..." << endl;
    for (const auto& testCase : testCases) {
        double totalDistance = 0.0;
        vector<string> resultPath = bestFirstSearch(graph, testCase.start, testCase.goal, totalDistance);
        assert(resultPath == testCase.expectedPath && "Best-First Search path did not match expected result.");
        assert(abs(totalDistance - testCase.expectedDistance) < 0.001 && "Best-First Search distance did not match expected result.");
        cout << "Best-First Search Test Passed for: " << testCase.start << " -> " << testCase.goal << endl;
    }

    // Test A* Search
    /*cout << "Testing A* Search..." << endl;
    for (const auto& testCase : testCases) {
        double totalDistance = 0.0;
        vector<string> resultPath = aStarSearch(graph, testCase.start, testCase.goal, totalDistance);
        assert(resultPath == testCase.expectedPath && "A* Search path did not match expected result.");
        assert(abs(totalDistance - testCase.expectedDistance) < 0.001 && "A* Search distance did not match expected result.");
        cout << "A* Search Test Passed for: " << testCase.start << " -> " << testCase.goal << endl;
    }*/

    cout << "All Unit Tests Completed." << endl;
}

int main() {
    // Parse the graph data from the existing files
    CityGraph graph;
    parseCities("coordinates.csv", graph);
    parseAdjacencies("Adjacencies.txt", graph);

    // Run the unit tests on the parsed graph
    runUnitTests(graph);

    return 0;
}
