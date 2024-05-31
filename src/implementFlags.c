#include "standard_headers.h"
#include "argparser.h"
#include "implementFlags.h"
#include "statistics.h"
  
  void print_help_page ()
  {
        printf ("Usage: ./pagerank [OPTIONS] ... [FILENAME]\nPerform pagerank computations for a given file in the DOT format\n"
                "\n"
                "\t-h      Print a brief overview of the available command line parameters\n"
                "\t-r N    Simulate N steps of the random surfer and output the result\n"
                "\t-m N    Simulate N steps of the Markov chain and output the result\n"
                "\t-s      Compute and print the statistics of the graph as defined in section 3.4\n"
                "\t-p P    Set the parameter p to P%%. (Default: P = 10)\n");
  }

  void print_graph_statistics (){

        //Error handling: if -h is absent and filename is also absent
        if (optional_filename == NULL || optional_filename[0] == '\0')
        {
            return;
        }
        
        
        // Create a graph from a filename string and print name
        graph * gr = readFile_createStructure (optional_filename);

        if (gr == NULL)
        {
            //exit(1);
            return;
        }
        
        printf ("%s:\n" ,  gr->name );


        // Calculate different properties of graph


            // Calculate number of nodes
            int num_nodes = 0;
            calculate_nodes ( gr , &num_nodes);
            printf ("- num nodes: %d\n" ,  num_nodes );

            // // Calculate number of edges
            int num_edges = 0;
            calculate_edges (gr , &num_edges);
            printf ("- num edges: %d\n" ,  num_edges );


            // // Calculate indegree
            int indegree [2]  = {0,0};
            calculate_indegree ( gr , indegree);
            printf ("- indegree: %d-%d\n" ,  indegree[0] , indegree[1] );


            // // Calculate number of nodes
            int outdegree [2] = {0,0};
            calculate_outdegree(gr , outdegree);
            printf ("- outdegree: %d-%d\n" ,  outdegree[0] , outdegree[1] );
        
        
        // Destroy the graph and all its nodes maybe using the node count

            for (int i = 0; i < gr->node_count; i++)
            {
                // 1 destroy both edge for node[i]
                destroyEdge  (gr->node[i]->inEdge);
                destroyEdge  (gr->node[i]->outEdge);

                // 2 destroy node[i]
                destroyNode  (gr->node[i]);

            }

            destroyGraph (gr);
        
    return;
        
  }

