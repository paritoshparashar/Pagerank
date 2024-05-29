#ifndef STATISTICS_H
#define STATISTICS_H


/* 
Calculate_nodes -> 
Takes pointer to a filename, and pointer to an int
Calculates the number of nodes in the graph in input file,
and stores it in the pointer num_nodes
*/
void calculate_nodes (char * input_file , int* num_nodes);



int calculate_edges ();
int* calculate_indegree ();
int* calculate_outdegree ();

#endif
