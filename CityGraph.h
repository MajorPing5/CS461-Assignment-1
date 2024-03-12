// CityGraph.h
#ifndef CITYGRAPH_H
#define CITYGRAPH_H

#include <vector>
#include <unordered_map>
#include <string>

using std::string;
using std::vector;
using std::unordered_map;

struct City {
    string name;
    double latitude;
    double longitude;
    vector<string> adjacents;
};

typedef unordered_map<string, City> CityGraph;

// Function prototypes for search algorithms
vector<string> breadthFirstSearch(const CityGraph& graph, const string& start, const string& goal);
// Other prototypes...

#endif // CITYGRAPH_H
