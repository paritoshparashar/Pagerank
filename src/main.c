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
  else if (optional_filename == NULL || optional_filename[0] == '\0')  
  {
    exit (1);
  }
  
  if (s_flag == 1)
  {
    print_graph_statistics();
  }

  if (r_flag == 1)
  {
    if (r_val < 1 || p_val < 1)
    {
      exit (1);
    }
    
    print_randomSurfer_pagerank ();
  }
  
  if (m_flag == 1)
  {
    if (m_val < 1 || p_val < 1)
    {
      exit (1);
    }

    print_markovChains_pagerank ();
  }
  

  // Error: No argument given
  if (s_flag != 1 && r_flag != 1 && m_flag != 1 && h_flag != 1)
  {
    exit (1);
  }


  
return 0;
  // exit(0);
}
