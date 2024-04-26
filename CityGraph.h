// CityGraph.h
#ifndef CITYGRAPH_H
#define CITYGRAPH_H

#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

struct City {
    string name;
    double latitude = 0.0;
    double longitude = 0.0;
    vector<string> adjacents;

    // Euclidean distance formula for a 2D plane
    // Note: This is only in use due to the small-scale nature of the data
    double distanceTo(const City& other) const {
        double xDiff = longitude - other.longitude;
        double yDiff = latitude - other.latitude;
        return sqrt(xDiff * xDiff + yDiff * yDiff);
    }
};

// Graph type definition for clarity
using Graph = unordered_map<string, vector<string>>;

typedef unordered_map<string, City> CityGraph;

/*  Breadth First Search - An algorithm that focuses on finding the neighboring nodes of all nodes at depth i
    before iterating by 1, visiting every child till the goal is found
    Parameters:
    @param graph    =   Full Graph given by coordinates.csv and Adjacencies.txt, constant variable
    @param start    =   User Inputted Variable, constant variable upon execution
    @param goal     =   User Inputted Variable, constant variable upon execution */
vector<string> breadthFirstSearch(const CityGraph& graph, const string& start, const string& goal, double& totalDistance);

/*  Depth First Search - An Algorithm that focuses on going as deep into a tree as possible, taking note of
    all nodes up to max depth before backtracking to find any alternative routes upon discovery of a dead end,
    non-goal node.
    Parameters:
    @param graph    =   Full Graph given by coordinates.csv and Adjacencies.txt, constant variable
    @param start    =   User Inputted Variable, constant variable upon execution
    @param goal     =   User Inputted Variable, constant variable upon execution */
vector<string> depthFirstSearch(const CityGraph& graph, const string& start, const string& goal, double& totalDistance);

vector<string> IDDFS(const CityGraph& graph, const string& start, const string& goal);

#endif // CITYGRAPH_H
