#include "argparser.h"
#include <stdio.h>
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
        
        FILE* input_file = fopen (optional_filename , "r");
        
        // Error: File did not open
        if (input_file == NULL)
        {
            fclose (input_file);
            return;
        }
        
        // Read the graph name for printing

        char graph_name[40]; // Contains the graph name

        if (fscanf (input_file , "digraph %39s {" , graph_name) != 1)
        {
            fclose (input_file);
            return;                                 // Error: reading the file
        }

        fclose (input_file);


        // Calculate different properties of graph


            // Call calculate_nodes to get the number of nodes in num_nodes
            int num_nodes = 0;
            calculate_nodes (optional_filename , &num_nodes);

            

        printf ("%s:\n"
                "- num nodes: %d" ,  graph_name, num_nodes );

  }

