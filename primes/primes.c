#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int * primes(int n) {
	int v[99999] = {0}; // sets array with all zeroes
	static int new[99999] = {0};
	int i, j, root;

	root = (int) floor(sqrt((float) n));

	for ( i=2 ; i<=root ; i++ ){
		if ( v[i] != 1 ){
			for ( j=i*i ; j<=n ; j=j+i ) {
				v[j] = 1; // marks element as eliminated from prime list
			}
		}
	}

	i=0;
	for ( j=2 ; j<=n ; j++ ){
		if ( v[j] == 0 ){
			new[i] = j;
			i++;
		}
	}

	return new;
}

void prints_array(int *a) {
	int i=0;

	printf("%d", a[i]);
	i++;
	while( a[i] != 0 ){
		printf(", %d", a[i]);
		i++;
	}
	printf("\n");
}

int main (int argc, char *argv[]) {
	FILE *file;
	int n;
	int *prime_list;

	if ( argc != 2 ) {
		printf("Usage: %s filename\n", argv[0]);
	} else {
		file = fopen( argv[1], "rt");

		if ( file == NULL ) {
			printf("Unable to open file\n");
		} else {
			while ( fscanf(file, "%d", &n) != EOF ){
				prime_list = primes(n);
				printf("Primes before %d\n", n);
				prints_array(prime_list);
			}
		}
	}

	return 0;
}

