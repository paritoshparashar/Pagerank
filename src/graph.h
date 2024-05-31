#ifndef GRAPH_H
#define GRAPH_H

typedef struct edge
{
    int length;
    struct graph_node * * connection;

} edge;

// Strutcture of a graph node
typedef struct graph_node
{
    char * name;
    edge * outEdge;
    edge * inEdge;

}  graph_node;


// Structure of a graph
typedef struct graph 
{
    char* name;
    graph_node * * node;
    int node_count;

}  graph;


/*
Takes -> nothinh
Returns -> pointer to a newly created edge struct with default values
*/
edge* createEdge ();


/*
Takes -> pointer to an edge struct, a node
Returns -> void, side effect* add the node to the edge struct connection 
*/
void addNode_toEdge ( edge * ed , graph_node * node );


/*
Takes -> pointer to an edge struct
Returns -> void, side effect* frees all the memory used by an edge struct
*/
void destroyEdge ( edge * ed);


//____________________Helper methods for node below____________________//


/*
Takes -> node name, and
Returns -> pointer to the newly created node with deafult values
*/
graph_node * createNode (char * name);


/*
Takes -> pointer to a graph, a graph node, and
Returns -> void, side effect* joins the graph node, to the graph
*/
void addNode_toGraph ( graph* gr , graph_node * newNode );


/*
Takes -> pointer to a graph, a name string
Returns -> 1 if node with nodeName exits in gr, else 0
*/
int node_exists ( graph* gr , char * nodeName);


/*
Takes -> pointer to a graph, a name string
Returns -> node with the same name as input string,
*/
graph_node * findNode (graph * gr , char * strName);


/*
Takes -> pointer to a node
Returns -> void, side effect* frees all the memory used by an node struct 
*/
void destroyNode ( graph_node * node);


//____________________Helper methods for graph below____________________//


/*
Takes -> graph name
Returns -> pointer to the newly created graph with default values
*/
graph* createGraph ( char * name);


/*
Takes -> pointer to a graph
Returns -> void, side effect* frees all the memory used by an graph struct 
*/
void destroyGraph ( graph * gr);

#endif
