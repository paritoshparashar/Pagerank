#include "argparser.h"
#include <stdio.h>
#include "implementFlags.h"

  
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
    printf ("Hello is read the -s flag\n");
  }