// main.cpp
#include "CityGraph.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "IDDFS.h"
#include "BestFirstSearch.h"
#include "AStarSearch.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <chrono>

using namespace std;

string citiesFilename = "coordinates.csv";
string adjacenciesFilename = "Adjacencies.txt";
void parseCities(const string& filename, CityGraph& graph);
void parseAdjacencies(const string& filename, CityGraph& graph);

int main() {
    // Variable used for user selection of algorithms
    int selection = 0;
    
    // Variable used for calculating drive time, can be adjusted for better modularity
    double speed = 60;

    // Initialize the graph structure
    CityGraph graph;

    // Call functions to parse cities from CSV & txt files
    parseCities(citiesFilename, graph);
    parseAdjacencies(adjacenciesFilename, graph);

    // Rest of your main function (user interaction, algorithm selection, etc.)
    cout << "Welcome to the Search Method Program! Please select your preferred search algorithm/technique"
            " by the number indicated to the left of the option (numbers only, no symbols):\n"
            "[1] Breath First Search\n"
            "[2] Depth First Search\n"
            "[3] Iterative Deepening Depth First Search\n"
            "[4] Best-First Search\n"
            "[5] A* Search\n"
            "[6] Quit" << endl;
    cin  >> selection;
    
    while (selection != 6) {
        string start = "";
        string goal = "";
        double totalDistance = 0.0;
        
        cout << "Submit the starting point name: ";
        cin >> start;
        cout << "Submit the objective name: ";
        cin >> goal;

        switch (selection) {
        case 1: {
            // System Timer Begins
            chrono::time_point<chrono::high_resolution_clock> timeStart = chrono::high_resolution_clock::now();

            vector <string> path = breadthFirstSearch(graph, start, goal, totalDistance);

            // System Timer Ends
            chrono::time_point<chrono::high_resolution_clock> timeStop = chrono::high_resolution_clock::now();

            // Calculate duration
            chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(timeStop - timeStart);

            if (!path.empty()) {
                cout << "Path found: ";
                for (const auto& city : path) {
                    cout << city << " -> ";
                }
                cout << "\nTotal Distance: " 
                    << totalDistance << endl;
                cout << "Time taken to find the route: "
                    << duration.count() << " microseconds" << endl;
            } else {
                cout << "No path found." << endl;
                cout << "Time taken to find the route: NaN milliseconds" << endl;
            }
            break;
        }
        case 2: {
            // System Timer Begins
            chrono::time_point<chrono::high_resolution_clock> timeStart = chrono::high_resolution_clock::now();

            const vector <string> path = depthFirstSearch(graph, start, goal, totalDistance);

            // System Timer Ends
            chrono::time_point<chrono::high_resolution_clock> timeStop = chrono::high_resolution_clock::now();

            // Calculate duration
            chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(timeStop - timeStart);

            if (!path.empty()) {
                cout << "Path found: ";
                for (const auto& city : path) {
                    cout << city << " -> ";
                }
                cout << "\nTotal Distance: "
                    << totalDistance << endl;
                cout << "Time taken to find the route: "
                    << duration.count() << " microseconds" << endl;
            } else {
                cout << "No path found." << endl;
                cout << "Time taken to find the route: NaN milliseconds" << endl;
            }
            break;
        }
        case 3: {
            chrono::time_point<chrono::high_resolution_clock> timeStart = chrono::high_resolution_clock::now();
            vector<string> path = IDDFS(graph, start, goal);
            chrono::time_point<chrono::high_resolution_clock> timeStop = chrono::high_resolution_clock::now();
            chrono::microseconds duration = chrono::duration_cast<chrono::microseconds>(timeStop - timeStart);

            if (!path.empty()) {
                cout << "Path found using IDDFS: ";
                for (const auto& city : path) {
                    cout << city << " -> ";
                }
                cout << "end\n";
                cout << "Time taken to find the route: " << duration.count() << " microseconds\n";
            }
            else {
                cout << "No path found using IDDFS." << endl;
                cout << "Time taken to find the route: NaN microseconds\n";
            }
            break;
        }
        case 4: {
            cout << "Algorithm incomplete" << endl;
            break;
        }
        case 5: {
            cout << "Algorithm incomplete" << endl;
            break;
        }
        default:
            cout << "Input not recognized. Try again." << endl;
        }
        cout << "For another algorithm, select a different number than your previous entry. Else, enter 6 to quit the program:" << endl
            << "[1] Breath First Search" << endl
            << "[2] Depth First Search" << endl
            << "[3] Iterative Deepening Depth First Search" << endl
            << "[4] Best-First Search" << endl
            << "[5] A* Search" << endl
            << "[6] Quit" << endl;
        cin >> selection;
    }

    system("pause");
    return 0;
}

//  Function intended to begin reading and processing the cities within Coordinates.csv
void parseCities(const string& filename, CityGraph& graph) {
    ifstream file(filename);
    ifstream adjFile(adjacenciesFilename);
    string line;
    
    /*  As of typing, there is NO header line within the csv file. For this to work,
        there cannot be a header line within the csv else this breaks the program reading */

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