// CityGraph.h
#ifndef CITYGRAPH_H
#define CITYGRAPH_H

#include <vector>
#include <unordered_map>
#include <string>
#include <cmath>

using std::string;
using std::vector;
using std::unordered_map;

struct City {
    string name = "";
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
using CityGraph = unordered_map<string, City>;

#endif // CITYGRAPH_H
