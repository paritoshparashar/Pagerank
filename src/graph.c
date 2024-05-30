#include "standard_headers.h"
#include "graph.h"
// Structure of a link of a node (outLinks / inLinks) 



// Helper methods for graph below

graph* createGraph ( char * name ) {

    if (name == NULL)
    {
        return NULL;
    }

                                                                // MALLOC *******
    graph* gr = (graph* ) malloc (sizeof (graph));

    // If malloc fails to assign mem
    if (gr == NULL)
    {
        return NULL;
    }

    // Set the default values of a node

                                                                // MALLOC *******
    gr->name = (char*)malloc (40* sizeof (char));
    strcpy (gr->name , name);

    gr->node = NULL;
    gr->node_count = 0;

    return gr;

}

// Helper methods for node below

graph_node * createNode ( char * name) {

    if (name == NULL)
    {
        return NULL;
    }

                                                                // MALLOC *******
    graph_node * newNode = (graph_node *)malloc (sizeof (graph_node));

    // If malloc fails to assign mem
    if (newNode == NULL)
    {
        return NULL;
    }

    // Set the default values of a node

                                                                // MALLOC *******
    newNode->name = (char*)malloc (40* sizeof (char));
    strcpy (newNode->name , name);

    newNode->outEdge = NULL;
    newNode->inEdge = NULL;

    return newNode;
}


void addNode_toGraph ( graph* gr , graph_node * newNode ) {

    // Assign a new container to the [node pointer] array of a graph
    
                                                                // MALLOC *******
    gr->node = realloc (gr->node , (gr->node_count +1) * (sizeof (graph_node *)) );

    if ((gr->node) == NULL)
    {
        return ;
    }

    //Assign the new node at[nodecount] (intially count = 0) 
    gr->node[gr->node_count] = newNode;
    gr->node_count = (gr->node_count) + 1;
    
}

int node_exists ( graph* gr , char * nodeName) {

    if (gr == NULL || nodeName == NULL)
    {
        return 0;
    }
    
    
    for (int i = 0; i < gr->node_count; i++)
    {
        
        if (strcmp (gr->node[i]->name , nodeName) == 0) // if node names are same i.e.(=0)
        {
            return 1; // true (node exists)
        }
        
    }

    return 0; // false (no such node exists)
    
}
