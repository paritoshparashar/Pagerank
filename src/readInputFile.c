#include "standard_headers.h"

graph* readFile_createStructure ( char * input_filename ) {    

    FILE* file = fopen (input_filename , "r");
        
        // Error: File did not open
        if (file == NULL)
        {
            fclose (file);
            exit (1);
        }

        char graph_name[256];

        if (fscanf (file , "digraph %255s {" , graph_name) != 1)
        {
            fclose (file);
            exit (1);                               // Error: reading the file
        }

        graph *gr = createGraph (graph_name);


        //________________Create the structure below_________________//


        char strA [256];
        char strB [256];

        /*
        Need to handle error in the input file
        Works for correct input now!
        */ 

        while ( fscanf (file , "%255s -> %255[^;];", strA, strB ) == 2)
        {


            if (!is_valid_identifier(strA) || !is_valid_identifier(strB)) {
                break;
            }

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
        if (strcmp (strA , "}") != 0)
        {
            fclose (file);
            recursive_graph_destroy (gr);
            exit (1);
        }
        

    fclose (file);

    return gr;
}


int is_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int is_digit(char c) {
    return c >= '0' && c <= '9';
}

int is_valid_identifier(const char *id) {
    if (!is_letter(id[0])) return 0; // The first character must be a letter
    for (int i = 1; id[i] != '\0'; i++) {
        if (!is_letter(id[i]) && !is_digit(id[i])) return 0; // All characters must be alphanumeric
    }
    return 1;
}

