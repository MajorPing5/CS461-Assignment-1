#pragma once

#ifndef BreadthFirstSearch_H
#define BreadthFirstSearch_H

#include "CityGraph.h"
#include <vector>

using namespace std;

/*  Breadth First Search - An algorithm that focuses on finding the neighboring nodes of all nodes at depth i
    before iterating by 1, visiting every child till the goal is found
    Parameters:
    @param graph    =   Full Graph given by coordinates.csv and Adjacencies.txt, constant variable
    @param start    =   User Inputted Variable, constant variable upon execution
    @param goal     =   User Inputted Variable, constant variable upon execution */
vector<string> breadthFirstSearch(const CityGraph& graph, const string& start, const string& goal, double& totalDistance);

#endif