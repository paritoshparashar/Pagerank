#include "standard_headers.h"

graph* readFile_createStructure ( char * input_filename ) {


    //Error handling: if -h is absent and filename is also absent

    if (input_filename == NULL /*|| input_filename[0] == '\0'*/ )  // Check 2nd or condition later
    {
        return NULL;
    }
    

    FILE* file = fopen (input_filename , "r");
        
        // Error: File did not open
        if (file == NULL)
        {
            fclose (file);
            return NULL ;
        }

        char graph_name[40];

        if (fscanf (file , "digraph %39s {" , graph_name) != 1)
        {
            fclose (file);
            return NULL;                                 // Error: reading the file
        }

        graph *gr = createGraph (graph_name);


        //________________Create the structure below_________________//


        char strA [40];
        char strB [40];

        /*
        Need to handle error in the input file
        Works for correct input now!
        */ 

        while ( fscanf (file , "%39s -> %39[^;];", strA, strB ) == 2)
        {
            /*
            Check if any node with strA/B name exists, 
            if it doesn't, create node && add node, 
            else move on
            */ 
            graph_node * newNodeA;
            graph_node * newNodeB;

            if (node_exists (gr , strA) == 0) // If node deosn't exist
            {
                newNodeA = createNode (strA);
                addNode_toGraph (gr , newNodeA );
            }
            
            if (node_exists (gr , strB) == 0) // If node deosn't exist
            { 
                newNodeB = createNode (strB);
                addNode_toGraph (gr, newNodeB );
            }

            
            
            
        }

        // for (int i = 0; i < gr->node_count; i++)
        // {
        //     printf ("%s, ", gr->node[i]->name);
        // }
        
        


    char end = '}';
        
    if (EOF != fscanf (file , "%s" , &end))
    {
        // Error in reading the whole file
        exit (1);
    }

    return gr;
}
