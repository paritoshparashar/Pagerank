/*
 * main.c
 *
 * Programming 2 - Project 3 (PageRank)
 */

#include <stdio.h>
#include <stdlib.h>
#include "argparser.h"
#include "utils.h"
#include "implementFlags.h"


int main(int argc, char *const *argv) {

  // initialize the random number generator
  rand_init();

  // TODO: Implement me
  parse_cmd_line_parameters (argc , argv); // Parse arguments using argparser.c

  // Conditino if -h is true
  if (h_flag == 1)
  {
    print_help_page();
    return 0;
  }
  if (s_flag == 1)
  {
    print_graph_statistics();
  }
  

  exit(0);
}
