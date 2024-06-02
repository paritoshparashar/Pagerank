#ifndef READINPUTFILE_H
#define READINPUTFILE_H
#include "standard_headers.h"


/*
Takes -> indput file name,
Returns -> pointer to a graph 
(reads the file, and builds a graph) 
*/
graph * readFile_createStructure ( char * input_file );

int is_letter(char c);

int is_digit(char c);

int is_valid_identifier(const char *id);
#endif
