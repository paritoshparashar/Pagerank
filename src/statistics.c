#include <stdio.h>
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

        
}

int calculate_edges (){

}


// Returns an int array [min, max] of indegree of graph
int* calculate_indegree (){

}


//Returns an int array [min,max] of outdegree of graph
int* calculate_outdegree (){

}
