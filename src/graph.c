#include "standard_headers.h"
#include "graph.h"
// Structure of a link of a node (outLinks / inLinks) 


graph_node * createNode (const char * name) {

    if (name == NULL)
    {
        return NULL;
    }

    graph_node * newNode = (graph_node *)malloc (sizeof (graph_node));
    if (newNode == NULL)
    {
        return NULL;
    }

    // Set the default values of a node

    /* Only copy 39 characters, 
    explicitly put the last character to be null*/
    strncpy (newNode->name , name, 39);
    newNode->name [39] = '\0'; 
    
    newNode->outEdge.length = 0;
    newNode->outEdge.connection = NULL;

    newNode->inEdge.length = 0;
    newNode->inEdge.connection = NULL;

    return newNode;
}


void addNode_toGraph ( graph* gr , graph_node * newNode ) {

    // Assign a new container to the node pointer array of a graph
    gr->node = realloc (gr->node , (gr->node_count +1) * (sizeof (graph_node *)) );

    if ((gr->node) == NULL)
    {
        return ;
    }

    //Assign the new node at[nodecount] (intially count = 0) 
    gr->node[gr->node_count] = newNode;
    ++gr->node_count;
    
}

int node_exists ( graph* gr , char * nodeName) {

    for (int i = 0; i < gr->node_count; i++)
    {
        if (strcmp (gr->node[i]->name , nodeName) == 0) // if node names are same i.e.(=0)
        {
            return 1; // true (node exists)
        }
        
    }
    return 0; // False (no such node exists)
    
}
