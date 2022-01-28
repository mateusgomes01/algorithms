#include <stdio.h>
#include <stdlib.h>

int euclid(int m, int n){
	if( n == 0 ){
		return m;
	} else {
		return euclid(n, m%n);
	}
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

