#pragma once
#ifndef DepthFirstSearch_H
#define DepthFirstSearch_H

#include "CityGraph.h"
#include <vector>

/*  Depth First Search - An Algorithm that focuses on going as deep into a tree as possible, taking note of
    all nodes up to max depth before backtracking to find any alternative routes upon discovery of a dead end,
    non-goal node.
    Parameters:
    @param graph    =   Full Graph given by coordinates.csv and Adjacencies.txt, constant variable
    @param start    =   User Inputted Variable, constant variable upon execution
    @param goal     =   User Inputted Variable, constant variable upon execution 
    @return totalDistance = Euclidian Distance calculated across the path */
vector<string> depthFirstSearch(const CityGraph& graph, const string& start, const string& goal, double& totalDistance);

#endif