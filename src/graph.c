#include "standard_headers.h"
#include "graph.h"



//____________________Helper methods for edges below____________________//

edge* createEdge () {

                                                                // MALLOC *******
    edge* ed = (edge* ) malloc (sizeof (edge));

    // If malloc fails to assign mem
    if (ed == NULL)
    {
        return NULL;
    }

    // Set the default values of a node
    ed->length = 0;
    ed->connection = NULL;

    return ed;

}

void addNode_toEdge ( edge * ed , graph_node * node ) {

    // Assign a new container to the [node pointer] array of a graph

                                                                // MALLOC *******
    ed->connection = realloc (ed->connection , (ed->length +1) * (sizeof (graph_node *)) );

    if ((ed->connection) == NULL)
    {
        return ;
    }

    //Assign the new node at [edLength] (intially length = 0) 
    ed->connection[ed->length] = node;
    ed->length = (ed->length) + 1;
    
}

void destroyEdge ( edge * ed) {

    /*
    First free the edge connection array,
    then the edge struct itself
    */ 
    free((*ed).connection); 
    ed->connection = NULL; // Handling dangling pointer maybe!?
    free (ed);
}


//____________________Helper methods for node below____________________//

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

graph_node * findNode (graph * gr , char * strName) {

    for (int i = 0; i < gr->node_count; i++)
    {
        if (strcmp (gr->node[i]->name , strName) == 0)
        {
            return gr->node[i];
        }
        
    }

    // Did not find node
    return NULL; 
    
}

void destroyNode ( graph_node * node){

    free(node->name); // I malloced the name too for some reason
    node->name = NULL;

    node->outEdge = NULL;
    node->inEdge = NULL;

    free (node);
}


//____________________Helper methods for graph below____________________//


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

void destroyGraph ( graph * gr) {

    free (gr->name);
    free (gr->node);
    free (gr);

}
