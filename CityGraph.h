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
    int heuristic = 0;

    // Euclidean distance formula for a 2D plane
    // Note: This is only in use due to the small-scale nature of the data
    double distanceTo(const City& other) const {
        double xDiff = longitude - other.longitude;
        double yDiff = latitude - other.latitude;
        return sqrt(xDiff * xDiff + yDiff * yDiff);
    }
};

// Simple Graph type definition for use with BFS, DFS, and IDDFS algorithms only
using simpleGraph = unordered_map<string, vector<string>>;

// Advanced Graph type definition for clarity and segregation between algorithms
using advancedGraph = unordered_map<string, City>;

/*  Breadth First Search - An algorithm that focuses on finding the neighboring nodes of all nodes at depth i
    before iterating by 1, visiting every child till the goal is found
    Parameters:
    @param graph    =   Full Graph given by coordinates.csv and Adjacencies.txt, constant variable
    @param start    =   User Inputted Variable, constant variable upon execution
    @param goal     =   User Inputted Variable, constant variable upon execution
    @return path    =   Valid path made from start to goal, or {} should the path be impossible*/
vector<string> breadthFirstSearch(const simpleGraph& graph, const string& start, const string& goal, double& totalDistance);

/*  Depth First Search - An Algorithm that focuses on going as deep into a tree as possible, taking note of
    all nodes up to max depth before backtracking to find any alternative routes upon discovery of a dead end,
    non-goal node.
    Parameters:
    @param graph    =   Full Graph given by coordinates.csv and Adjacencies.txt, constant variable
    @param start    =   User Inputted Variable, constant variable upon execution
    @param goal     =   User Inputted Variable, constant variable upon execution 
    @return path    =   Valid path made from start to goal, or {} should the path be impossible*/
vector<string> depthFirstSearch(const simpleGraph& graph, const string& start, const string& goal, double& totalDistance);

/* Itterative Deepening - Depth First Search - An Algorithm that focuses on traversing the given graph at a small depth, 
    gradually increasing its depth value until it is able to reach its objective from the starting position.
    Parameters:
    @param graph    =
    @param start    =
    @param goal     =
    @return path    = Valid path made from start to goal, or {} should the path be impossible*/
vector<string> IDDFS(const simpleGraph& graph, const string& start, const string& goal);

#endif // CITYGRAPH_H
