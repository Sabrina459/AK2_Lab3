#include <iostream>
#include <unistd.h>
#include <getopt.h>
#include <vector>
#include <time.h>
#include <string>

using namespace std;

void help();
void scared(const int);
void left(const char*);


int main(int argc, char* argv[]) {
    int rez = -1;
    int option_index;
    srand(time(NULL));
    const char* short_options = "hs::l:";
    const struct option long_options[] = {
            {"help",no_argument,NULL,'h'},
            {"scared",optional_argument,NULL,'s'},
            {"left",required_argument,NULL,'l'},
            {NULL,0,NULL,0}
    };
    int h_counter = 1;
    int s_counter = 1;
    int l_counter = 1;


    while ((rez = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {

        switch (rez) {
        case 'h': {
            if (h_counter < 1) {
                break;
            }
            h_counter--;
            help();
            break;
        }
        case 's': {
            if (s_counter < 1) {
                break;
            }
            s_counter--;
            if (optarg != NULL && strlen(optarg) == 1 && (*optarg >= '0' && *optarg <= '9'))
                scared(*optarg -'0');
            else
                scared(10);
            

        break;
        }

        case 'l': {
            if (l_counter < 1) {
                break;
            }
            l_counter--;
            if (*optarg >= '0' && *optarg <= '9')
                left(optarg);
        break;
        }
        case '?': default: {
            printf("Unknown option\n");
            break;
        }
        }
    }
}

void help() {
    printf("Don't ask strangers for help \n");
}

void scared(const int number) {
    const vector<string> scarings{ "7 daysssss...", "Booo", "Fredy is here", "hhhhhhhhhhhhhhh"};
    int ran =  0;
    if (number == 10)
        ran = rand() % 4;
    else ran = number;

    printf((scarings[ran]).data() );
}

void left(const char* number) {
    printf("You will die after %s days\n",number);
}