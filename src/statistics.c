#include "standard_headers.h"
#include "statistics.h"



void calculate_nodes ( graph * gr, int* num_nodes){

        *num_nodes = gr->node_count;
}

void calculate_edges (graph * gr, int* num_edges){

    int totalEdges = 0;

    for (int i = 0; i < gr->node_count; i++)
    {
        totalEdges += gr->node[i]->outEdge->length;
    }
    
    *num_edges = totalEdges;
}


// Returns an int array [min, max] of indegree of graph
void calculate_indegree (graph * gr, int* inMinMax){
    return ;
}


//Returns an int array [min,max] of outdegree of graph
void calculate_outdegree (graph * gr, int* outMinMax){
    return ;
}

