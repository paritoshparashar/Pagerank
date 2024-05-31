#ifndef IMPLEMENTFLAG_H
#define IMPLEMENTFLAG_H


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

#endif
