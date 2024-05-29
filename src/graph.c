#include "standard_headers.h"

typedef struct graph_nodes
{
    char* name [40];
    struct graph_nodes* * outLinks;
    struct graph_nodes* * inLinks;
}  graph_nodes;
