#ifndef ARGPARSER_H
#define ARGPARSER_H

#include "standard_headers.h"

void parse_cmd_line_parameters (int argc , char *const *argv);

// extern int read_option; // Tracks the options read by getopt

extern  int h_flag;
extern  char* optional_filename;

 extern   int r_flag;
 extern   int r_val;

 extern   int m_flag;
 extern   int m_val;

 extern   int p_flag;
 extern   int p_val;

 extern   int s_flag;


#endif //ARGPARSER_H
