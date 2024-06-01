#ifndef IMPLEMENTFLAG_H
#define IMPLEMENTFLAG_H

#include "standard_headers.h"

/*
Implements the -h flag function
and writes to the standard output,
the help message for all the 
command line arguments of the program
*/
void print_help_page ();


/*
Implements the -s flag function
and writes to the standard output,
the statistics for a graph represented
by an input file (passed in cmd line)
*/
void print_graph_statistics ();


/*
Implements the -r flag function
and writes to the standard output,
the pageranks for every node of graph
represented by an input file (passed in cmd line)
using the random surfer method
*/
void print_randomSurfer_pagerank ();


/*
Implements the -m flag function
and writes to the standard output,
the pageranks for every node of graph
represented by an input file (passed in cmd line)
by creating markov chains
*/
void print_markovChains_pagerank ();


// Graph Methods //
graph* safelycreateGraph ();

void recursive_graph_destroy (graph * gr);

#endif
