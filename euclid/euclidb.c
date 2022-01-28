#include <stdio.h>
#include <stdlib.h>

/*
Euclids non-recursive algorithm to compute the greates common divisor of two integers
Mateus Melo
https://mateusmelo.xyz
*/

int euclid(int m, int n){
	int r;

	while( n != 0 ){
		r = m % n;
		m = n;
		n = r;
	}

	return m;
}

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
			while ( fscanf(file, "%d %d", &m, &n) != EOF ){
				printf("Euclid(%d,%d) = %d\n", m, n, euclid(m,n));
			}
		}
	}

	return 0;
}

