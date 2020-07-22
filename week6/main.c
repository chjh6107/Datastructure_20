#include <stdio.h>

int char_counting_sort(char A[], char B[], int n);

int main(int argc, char *argv[]) {
int n = 10;
char A[10] = {'c', 'b', 'c', 'd', 'E', 'C', 'a', 'A', 'b', 'C'};
char B[10];

for (int i = 0; i < n; i++) printf("%c ", A[i]);
printf("\n");

int res = char_counting_sort(A, B, n);

for (int i = 0; i < n; i++) printf("%c ", B[i]);
printf("\n");

printf("res = %d\n", res);
}