/*
 * main.c
 *
 * Programming 2 - Project 3 (PageRank)
 */

#include <stdio.h>
#include <stdlib.h>
#include "argparser.h"
#include "utils.h"

int main(int argc, char *const *argv) {

  parse_cmd_line_parameters (argc , argv);
  if (h_flag == 1)
  {
    printf ("Usage: ./pagerank [OPTIONS] ... [FILENAME]\nPerform pagerank computations for a given file in the DOT format\n"
            "\n"
            "\t-h      Print a brief overview of the available command line parameters\n"
            "\t-r N    Simulate N steps of the random surfer and output the result\n"
            "\t-m N    Simulate N steps of the Markov chain and output the result\n"
            "\t-s      Compute and print the statistics of the graph as defined in section 3.4\n"
            "\t-p P    Set the parameter p to P%%. (Default: P = 10)\n");
  }
  
  // initialize the random number generator
  //rand_init();

  // TODO: Implement me
  exit(0);
}
