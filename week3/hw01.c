#include<stdio.h>

int lsc(char *A, int p, int r)
{	
	int i, q, left, right;
    int res, cross = 0;
    int count = 0;
	if (p == r) 
        return 0;
    
    q = (p + r) / 2;
    left = lsc(A, p, q);
    printf("left = %d\n",left);
    right = lsc(A, q + 1, r);
    printf("right = %d\n",right);
	if (left > right)
        res = left;
	else
        res = right;
    printf("res = %d", res);
	for (i = q; i >= p && A[q] == A[i]; i--)
		cross++;
	for (i = q + 1; i <= r && A[q] == A[i]; i++)
		cross++;
	
	if (res < cross)
        res = cross;
	
    return res;
}