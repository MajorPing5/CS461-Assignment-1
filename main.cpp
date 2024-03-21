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
    //Variable used for user selection of algorithms
    int selection = 0;

    // Initialize the graph structure
    CityGraph graph;

    // Call functions to parse cities from CSV & txt files
    parseCities(citiesFilename, graph);
    parseAdjacencies(adjacenciesFilename, graph);

    // Rest of your main function (user interaction, algorithm selection, etc.)
    cout << "Welcome to the Search Method Program! Please select your preferred search algorithm/technique"
        << " by the number indicated to the left of the option (numbers only, no symbols):" << endl
        << "[1] Breath First Search" << endl
        << "[2] Depth First Search" << endl
        << "[3] Iterative Deepening Depth First Search" << endl
        << "[4] Best-First Search" << endl
        << "[5] A* Search" << endl
        << "[6] Quit" << endl;
    cin  >> selection;
    
    while (selection != 6) {
        
        switch (selection) {
        case 1:
            breadthFirstSearch(graph, start, goal);
            break();
        case 2:
            depthFirstSearch(graph, start, goal);
            break();
        case 3:
            cout << "Algorithm incomplete" << endl;
            break();
        case 4:
            cout << "Algorithm incomplete" << endl;
            break();
        case 5:
            cout << "Algorithm incomplete" << endl;
            break();
        default:
            cout << "Input not recognized. Try again." << endl;
        }
        cout << "For another algorithm, select a different number than your previous entry. Else, enter 6 to quit the program:" < , endl;
            << "[1] Breath First Search" << endl
            << "[2] Depth First Search" << endl
            << "[3] Iterative Deepening Depth First Search" << endl
            << "[4] Best-First Search" << endl
            << "[5] A* Search" << endl
            << "[6] Quit" << endl;
        cin >> selection;
    }


}


//  Function intended to begin reading and processing the cities within Coordinates.csv
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

//  Function intended to begin reading and processing city adjacency from Adjacencies.txt
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