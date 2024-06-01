#ifndef MARKOVCHAINS_H
#define MARKOVCHAINS_H

#include "standard_headers.h"

double * calculate_markovChains (graph * gr , double * state_probArr, double * matrix );

double *  calculate_probability_matrix (graph * gr);

int links_s1_to_s2 (graph_node * node_i , graph_node * node_j);
#endif
