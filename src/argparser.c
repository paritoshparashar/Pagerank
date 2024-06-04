#include "standard_headers.h"
#include "argparser.h"


    const char *options = "hr:m:sp:";

    int read_option; // Tracks the options read by getopt

    int h_flag = 0;

    char* optional_filename = NULL;

    int r_flag = 0;
    int r_val = 0;

    int m_flag = 0;
    int m_val = 0;

    int p_flag = 0;
    int p_val = 10;

    int s_flag = 0;

void parse_cmd_line_parameters (int argc , char *const *argv) {

    // Has a lot of errors that I still need to handle, like what happens when we have extra or too less inputs, or wrong inputs!

    while ((read_option = getopt (argc , argv , options)) != -1) {

        // Handle error, when one option is present in the command line twice -s -s (this will revert s in the current implementation to 0 again) we can handle this by an if (s_flag != 1) {} 
        
    switch (read_option) { 

        case -1:
            break;

        case 'h':
            h_flag = 1;
            break;
        
        case 'r':
            r_flag = 1;
            r_val = atoi(optarg);  // Where ever using atoi (3 cases below), beware that optarg could be a non-number or even point to null. Handle this case in the bonus task
            break;
        
        case 'm':
            m_flag = 1;
            m_val = atoi(optarg);
            break;

        case 's':
            s_flag = 1;
            break;

        case 'p':
            p_flag = 1;
            p_val = atoi(optarg);
            break;


        default:
            exit (1); // Will land here in case of an error (some other argument, other than the *options) use exit()
        }
    }

    // What happen if many tags are present along with h and filename??


     // If -h is present, the filename won't be, so don't do anything and return
    if (h_flag == 1)
    {
        return;
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
