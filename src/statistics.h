#ifndef STATISTICS_H
#define STATISTICS_H

#include "graph.h"

/* 
Calculate_nodes -> 
Takes -> pointer to a graph, pointer to an int
Return -> void , store the number of nodes in the num_nodes pointer
*/
void calculate_nodes ( graph * gr, int* num_nodes);

/* 
Calculate_nodes -> 
Takes -> pointer to a graph, pointer to an int
Return -> void , store the number of nodes in the num_nodes pointer
*/
void calculate_edges ( graph * gr, int* num_edges);

/* 
Calculate_nodes -> 
Takes -> pointer to a graph, pointer to an int
Return -> void , store the number of nodes in the num_nodes pointer
*/
void calculate_indegree ( graph * gr, int* inMinMax);

/* 
Calculate_nodes -> 
Takes -> pointer to a graph, pointer to an int
Return -> void , store the number of nodes in the num_nodes pointer
*/
void calculate_outdegree ( graph * gr , int* outMinMax);


#endif
