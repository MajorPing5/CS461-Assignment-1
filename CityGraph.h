// CityGraph.h
#ifndef CITYGRAPH_H
#define CITYGRAPH_H

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

using string;
using vector;
using unordered_map;

struct City {
    string name;
    double latitude;
    double longitude;
    vector<string> adjacents;
};

// Graph type definition for clarity
using Graph = unordered_map<string, vector<string>>;

typedef unordered_map<string, City> CityGraph;

/*  Breath First Search - An algorithm that focuses on finding the neighboring nodes of all nodes at depth i
    before iterating by 1, visiting every child till the goal is found
    Parameters:
    @param graph    =   Full Graph given by coordinates.csv, constant variable
    @param start    =   User Inputted Variable, constant variable upon execution
    @param goal     =   User Inputted Variable, constant variable upon execution */
vector<string> breadthFirstSearch(const CityGraph& graph, const string& start, const string& goal);

/*  Depth First Search - An Algorithm that focuses on going as deep into a tree as possible, taking note of
    all nodes up to max depth before backtracking to find any alternative routes upon discovery of a dead end,
    non-goal node.
    Parameters:
    @param graph    =   Full Graph given by coordinates.csv, constant variable
    @param start    =   User Inputted Variable, constant variable upon execution
    @param goal     =   User Inputted Variable, constant variable upon execution */
vector<string> depthFirstSearch(const CityGraph& graph, const string& start, const string& goal);

// Other prototypes...

#endif // CITYGRAPH_H
