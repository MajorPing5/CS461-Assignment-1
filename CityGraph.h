// CityGraph.h
#pragma once

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

    City(const string& name = "", double lat = 0.0, double lon = 0.0)
        : name(name), latitude(lat), longitude(lon) {}

    // Euclidean distance formula for a 2D plane
    // Note: This is only in use due to the small-scale nature of the data
    double distanceTo(const City& other) const {
        double xDiff = longitude - other.longitude;
        double yDiff = latitude - other.latitude;
        return sqrt(xDiff * xDiff + yDiff * yDiff);
    }
};

// Subclass within City, intended to be used by the more complex algorithms
struct HeuristicCity : City {
    double heuristic = 0.0;  // Default heuristic value

    // Constructor to initialize with heuristic
    HeuristicCity(const string& name = "", double lat = 0.0, double lon = 0.0, double heuristicValue = 0.0)
        : City(name, lat, lon), heuristic(heuristicValue) {}

    // Method to update heuristic based on a specific goal or other criteria
    void updateHeuristic(const City& goal) {
        // Example: Use a simple Euclidean distance as heuristic
        heuristic = distanceTo(goal);
    }
};

// Graph type definition for clarity
using Graph = unordered_map<string, vector<string>>;
using CityGraph = unordered_map<string, City>;

#endif // CITYGRAPH_H
