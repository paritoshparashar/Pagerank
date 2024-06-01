#include "standard_headers.h"

double * calculate_markovChains (graph * gr , double * state_probArr, double* matrix ) {

    
    double* nextState_probArr = malloc (gr->node_count * sizeof (double));

    for (int i = 0; i < gr->node_count; i++) // Iterating through the probability array pie
    {
        double mulSum = (double) 0;

        for (int j = 0; j < gr->node_count; j++)
        {
            mulSum += state_probArr[j] * matrix[(j*gr->node_count) + i];
        }
        nextState_probArr[i] = mulSum;

    }
    
    return nextState_probArr;
}

double *  calculate_probability_matrix (graph * gr){

    int matrixLength = gr->node_count * gr->node_count;
    double * matrix = malloc ( (matrixLength) * sizeof (double)); // Don't forget to free this later

    graph_node * * nodesArr = gr->node;

    double p = (double) (p_val / (double) 100);
    double bored_prob = (double) 1/gr->node_count; // 1/|S|

    for (int i = 0; i < (gr->node_count); i++)
    {
        for (int j = 0; j < gr->node_count; j++)
        {
            if (nodesArr[i]->outEdge->length == 0) // if out(s) = 0
            {
                matrix[(i*(gr->node_count)) + j] = bored_prob;
            }

            else // otherwise case
            {
                int totalDirectedLinks = links_s1_to_s2 (nodesArr[i] , nodesArr[j]);
                double staysInterested_prob = (double)((1-p)*((totalDirectedLinks)/(double)(nodesArr[i]->outEdge->length)));

                matrix[(i*(gr->node_count)) + j] = (double)(p * bored_prob) + staysInterested_prob; 
            }

        }

    }

    return matrix;
}

int links_s1_to_s2 (graph_node * node_i , graph_node * node_j) {

    int linkCounter = 0;

    for (int i = 0; i < node_i->outEdge->length; i++)
    {
        if (strcmp(node_i->outEdge->connection[i]->name, node_j->name) == 0 )
        {
            ++linkCounter;
        }
        
    }

    return linkCounter;
    
}


