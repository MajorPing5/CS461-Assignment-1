// main.cpp
#include "CityGraph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

string citiesFilename = "coordinates.csv";
string adjacenciesFilename = "Adjacencies.txt";
void parseCities(const string& filename, CityGraph& graph);
void parseAdjacencies(const string& filename, CityGraph& graph);

int main() {
    // Initialize the graph structure
    CityGraph graph;

    // Call functions to parse cities from CSV & txt files
    parseCities(citiesFilename, graph);
    parseAdjacencies(adjacenciesFilename, graph);

    // Rest of your main function (user interaction, algorithm selection, etc.)
}

void parseCities(const string& filename, CityGraph& graph) {
    ifstream file(filename);
    ifstream file(adjacenciesFilename);
    string line;
    
    /*  As of typing, there is NO header line within the csv file. For this to work,
        there cannot be a header line within the csv else this breaks the program reading */

    CityGraph graph;

    while (getline(file, line)) {
        stringstream linestream(line);
        string cityName, lat, lon;

        getline(linestream, cityName, ',');
        getline(linestream, lat, ',');
        getline(linestream, lon, ',');

        City city = { cityName, std::stod(lat), std::stod(lon), {} };
        graph[cityName] = city;
    }
}

void parseAdjacencies(const string& filename, CityGraph& graph) {
    ifstream file(filename);
    ifstream adjFile(adjacenciesFilename);
    string line;

    while (getline(adjFile, line)) {
        istringstream iss(line);
        string city1, city2;

        iss >> city1 >> city2;

        // Assuming symmetric adjacency
        graph[city1].adjacents.push_back(city2);
        graph[city2].adjacents.push_back(city1);
    }
}