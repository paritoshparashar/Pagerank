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
            graph_node * newNodeA = NULL;
            graph_node * newNodeB = NULL;

            // Add Nodes
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



            // Add Links to Nodes

            if (newNodeA != NULL) // Node A is new
            {
                if (newNodeB != NULL) // Both are new
                {
                    edge * outEd1 = createEdge ();
                    edge * inEd1 = createEdge ();
                    newNodeA->outEdge = outEd1; 
                    newNodeA->inEdge = inEd1; // Create both edges for the newnode
                    addNode_toEdge (newNodeA->outEdge , newNodeB);

                    edge * outEd2 = createEdge ();
                    edge * inEd2 = createEdge ();
                    newNodeB->outEdge = outEd2;
                    newNodeB->inEdge = inEd2;
                    addNode_toEdge (newNodeB->inEdge , newNodeA);
                }

                else // Node B is old
                {
                    edge * outEd1 = createEdge ();
                    edge * inEd1 = createEdge ();
                    newNodeA->outEdge = outEd1; 
                    newNodeA->inEdge = inEd1; // Create both edges for the newnode
                    addNode_toEdge (newNodeA->outEdge , findNode (gr , strB));

                    addNode_toEdge (findNode (gr , strB)->inEdge , newNodeA);
                } 
                
            }

            else // Node A is old
            {
                if (newNodeB != NULL) // Node B is new
                {
                    addNode_toEdge (findNode (gr , strA)->outEdge , newNodeB);

                    edge * outEd1 = createEdge ();
                    edge * inEd1 = createEdge ();
                    newNodeB->outEdge = outEd1; 
                    newNodeB->inEdge = inEd1; // Create both edges for the newnode
                    addNode_toEdge (inEd1 , findNode (gr, strA));
                }

                else // Both are old
                {
                    addNode_toEdge (findNode (gr , strA)->outEdge , findNode(gr , strB));

                    addNode_toEdge (findNode (gr , strB)->inEdge , findNode(gr , strA));
                }
                
            }
        
            
        }

    

    return gr;
}
