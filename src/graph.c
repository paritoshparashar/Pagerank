#include "standard_headers.h"

// Structure of a link of a node (outLinks / inLinks) 

typedef struct edge
{
    int length;
    struct graph_node * * connection;

} edge;

// Strutcture of a graph node
typedef struct graph_node
{
    char name [40];
    edge outEdge;
    edge inEdge;

}  graph_node;


// Structure of a graph
typedef struct graph 
{
    char name [40];
    graph_node * * node;

}  graph;



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

// void addNode_toGraph ( graph* gr , graph_node * newNode ) {


// }

