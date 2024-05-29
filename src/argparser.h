#ifndef ARGPARSER_H
#define ARGPARSER_H

void parse_cmd_line_parameters (int argc , char *const *argv);

// extern int read_option; // Tracks the options read by getopt

extern  int h_flag;
extern  char* optional_filename;
extern  char* r_flag;
extern  char* m_flag;
extern  int s_flag;
extern  char* p_flag;

#endif //ARGPARSER_H
