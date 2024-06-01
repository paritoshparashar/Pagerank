#ifndef RANDOMSURFER_H
#define RANDOMSURFER_H

#include "standard_headers.h"

int bored (int number_of_websites);
int notBored (int number_of_outlinks);
int findNodeIndex (graph * gr, graph_node * node);
double * startSurfing (  graph * gr ,int start_website);
#endif
