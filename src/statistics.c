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

    if (gr->node_count == 0)
    {
        return;
    }
    
    int min = gr->node[0]->inEdge->length;
    int max = gr->node[0]->inEdge->length;

    for (int i = 0; i < gr->node_count; i++)
    {

        // Calculate min indegree
        if (gr->node[i]->inEdge->length < min)
        {
            min = gr->node[i]->inEdge->length;
        }

        // Calculate max indegree
        if (gr->node[i]->inEdge->length > max)
        {
            max = gr->node[i]->inEdge->length;
        }
         
    }
    
    inMinMax[0] = min;
    inMinMax[1] = max;
    return ;
}


//Returns an int array [min,max] of outdegree of graph
void calculate_outdegree (graph * gr, int* outMinMax){

    if (gr->node_count == 0)
    {
        return;
    }

    int min = gr->node[0]->outEdge->length;
    int max = gr->node[0]->outEdge->length;

    for (int i = 0; i < gr->node_count; i++)
    {

        // Calculate min indegree
        if (gr->node[i]->outEdge->length < min)
        {
            min = gr->node[i]->outEdge->length;
        }

        // Calculate max indegree
        if (gr->node[i]->outEdge->length > max)
        {
            max = gr->node[i]->outEdge->length;
        }
         
    }
    
    outMinMax[0] = min;
    outMinMax[1] = max;
    
    return ;
}

