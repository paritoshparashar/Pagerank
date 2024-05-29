#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>


void parse_cmd_line_parameters (int argc , char *const *argv) {

    const char *options = "hr:m:sp:";

    int read_option; // Tracks the options read by getopt

    int h_flag = 0;
    char* optional_filename = NULL;
    char* r_flag = NULL;
    char* m_flag = NULL;
    int s_flag = 0;
    char* p_flag = NULL;

    while ((read_option = getopt (argc , argv , options)) != -1) {

        // Handle error, when one option is present in the command line twice -s -s (this will revert s in the current implementation to 0 again) we can handle this by an if (s_flag != 1) {} 
        
    switch (read_option) { 

        case -1:
            break;

        case 'h':
            h_flag = 1;
            break;
        
        case 'r':
            r_flag = optarg;
            break;
        
        case 'm':
            m_flag = optarg;
            break;

        case 's':
            s_flag = 1;
            break;

        case 'p':
            p_flag = optarg;
            break;


        default:
            break; // Will land here in case of an error (some other argument, other than the *options) use exit()
        }
    }


    if (h_flag == 0){

        // We expect a [FILENAME]

        if ( optind < argc )
        {
            // Handle Non option arguments  (like filename)

            optional_filename = argv[optind++];

        
        }

    }
    

    
    return ;

    
}