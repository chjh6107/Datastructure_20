#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lsc(char *A, int p, int r);

int main(int argc, char *argv[]){
	int l = strlen(argv[1]);
	// printf("(%s)(i = %d)\n", argv[1], l);

	printf("%d\n", lsc(argv[1], 0, l-1));
	return 0;	
}
