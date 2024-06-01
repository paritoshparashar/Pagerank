#include "standard_headers.h"

int bored ( int number_of_websites) {

    return randu (number_of_websites);

}

int notBored ( int number_of_outlinks ) {

    return randu (number_of_outlinks);
}

int findNodeIndex (graph * gr, graph_node * node) {

    for (int i = 0; i < gr->node_count; i++)
    {
        if (strcmp (gr->node[i]->name , node->name) == 0)
        {
            return i;
        }
        
    }
    return -1;
    
}

double * startSurfing ( graph * gr , int start_website_index) {

    int number_of_websites = gr->node_count;
    graph_node * * websiteArr = gr->node; // Node Array

    int website_visitCounter [number_of_websites];

    for (int i = 0; i < number_of_websites; i++)
    {
        website_visitCounter[i] = 0;
    }

    int current_website_index = start_website_index;
    int next_website_index;

    for (int i = 0; i < r_val; i++)  // Iterate -r (r_val)times
    {
        int rand_bored_prob = randu (100); // Generates a random number between 0 and 99 inclusively

        // If no outLinks, instantly bored, or if bored by probability
        if ( websiteArr[current_website_index]->outEdge->length == 0  || rand_bored_prob < p_val) 
        {
            next_website_index = bored (number_of_websites);
            current_website_index = next_website_index;

            ++website_visitCounter[current_website_index];
        }
        
        // Is interested
        else                     
        {
            int next_link = notBored ( websiteArr[current_website_index]->outEdge->length);
            graph_node * nextConnectionNode = websiteArr[current_website_index]->outEdge->connection[next_link];
            next_website_index = findNodeIndex (gr , nextConnectionNode);

            if ( next_website_index != -1) {            // Error handling
                current_website_index = next_website_index;
            }

            ++website_visitCounter[current_website_index];
        }
        
    }
    
double * ranks = malloc (number_of_websites * sizeof (double));

for (int i = 0; i < number_of_websites; i++)
{
    ranks[i] = (double) website_visitCounter[i]/r_val;
}

return ranks;

}
