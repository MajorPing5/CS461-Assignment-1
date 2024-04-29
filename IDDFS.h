#pragma once
#ifndef IDDFS_H
#define IDDFS_H

#include "CityGraph.h"
#include <vector>

/*  Iterative Deepening Depth First Search - An Algorithm that focuses on going as deep into a tree as possible, taking note of
    all nodes up to max depth before backtracking to find any alternative routes upon discovery of a dead end, non-goal node.
    Parameters:
    @param graph    =   Full Graph given by coordinates.csv and Adjacencies.txt, constant variable
    @param start    =   User Inputted Variable, constant variable upon execution
    @param goal     =   User Inputted Variable, constant variable upon execution */
vector<string> IDDFS(const CityGraph& graph, const string& start, const string& goal);

#endif