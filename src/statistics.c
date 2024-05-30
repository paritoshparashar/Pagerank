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

        while ( fscanf (file , "%39s -> %39[^;];", nodeA, nodeB ) == 2)
        {
            /*Need to handle error in the input file
            Works for correct input now!
            */ 
            if (1)
            {
                // Check if any node with nodeA string name exists, if yes, move on, else create node and add node
                
                printf ("%s -> %s\n", nodeA, nodeB);
            }
            
        }


        char end = '}'; 
        if (EOF != fscanf (file , "%s" , &end))
        {
            // Error in reading the whole file
            exit (1);
        }
        
        

}

int calculate_edges (){
    return 1;
}


// Returns an int array [min, max] of indegree of graph
int* calculate_indegree (){
    return NULL;
}


//Returns an int array [min,max] of outdegree of graph
int* calculate_outdegree (){
    return NULL;
}
