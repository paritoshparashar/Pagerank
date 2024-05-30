#include "standard_headers.h"

#include "statistics.h"

void calculate_nodes (char * input_file , int* num_nodes){

    FILE* file = fopen (input_file , "r");
        
        // Error: File did not open
        if (input_file == NULL)
        {
            fclose (file);
            return ;
        }

        fscanf (file , "%*[^\n]\n"); // Reads the first line without saving it

        char nodeA [40];
        char nodeB [40];

        while ( fscanf (file , "%39s -> %39s;", nodeA, nodeB ) != EOF)
        {
            if (1)
            {
                /* code */ // Check if any node with nodeA string name exists, if yes, move on, else create node and add node
            }
            
        }
        

}

int calculate_edges (){

}


// Returns an int array [min, max] of indegree of graph
int* calculate_indegree (){

}


//Returns an int array [min,max] of outdegree of graph
int* calculate_outdegree (){

}
