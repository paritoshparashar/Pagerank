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
Takes -> pointer to an edge struct, a node
Returns -> void, side effect* add the node to the edge struct connection 
*/
void addNode_toEdge ( edge * ed , graph_node * node );


/*
Takes -> nothinh
Returns -> pointer to a newly created edge struct with default values
*/
edge* createEdge ();


/*
Takes -> graph name, and
Returns -> pointer to the newly created graph with default values
*/
graph* createGraph ( char * name );


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

#endif

