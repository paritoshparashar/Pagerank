/*
 * main.c
 *
 * Programming 2 - Project 3 (PageRank)
 */

#include "standard_headers.h"
#include "utils.h"


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
  // If h == 0, then filename better not point to NULL
  else if (optional_filename == NULL)  
  {
    return 1;
  }
  

  if (s_flag == 1)
  {
    print_graph_statistics();
  }

  // if (p_flag == 1)
  // {
  //   printf ("P - %d\n" , p_val);  /*Doesn't matter if p is true or not*/
  // }
  

  if (r_flag == 1)
  {
    print_randomSurfer_pagerank ();
  }
  
  

  

  // exit(0);
}
