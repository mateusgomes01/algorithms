#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	FILE *file;
	int m, n;

	if( argc != 2 ) {
		printf("Usage: %s filename\n", argv[0]);
	} else {
		file = fopen( argv[1], "rt");

		if ( file == NULL ) {
			printf("Unable to open file\n");
		} else {
			// Your code goes here
		}
	}

	return 0;
}

