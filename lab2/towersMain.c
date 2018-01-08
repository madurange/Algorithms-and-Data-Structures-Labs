#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;

    if (argc > 4 || argc == 3) {
        fprintf(stderr, "Invaid Argument Used");
		exit(1);
    }else{
		if (argc > 1) {
			n = atoi(argv[1]);
			if(n<=0){
				fprintf(stderr, "Invaid Argument Used");
				exit(1);
			}
		}
		if (argc > 3) {
			from=atoi(argv[2]);
			dest=atoi(argv[3]);
			if(from < 1 || dest < 1 || from > 3 || dest > 3 || from == dest){
				fprintf(stderr, "Invaid Argument Used");
				exit(1);
			}
		}
	}
    towers(n, from, dest);
    exit(0);
}

