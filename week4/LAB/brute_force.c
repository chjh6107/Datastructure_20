#include <stdio.h>

void find_maximum_subarray_brute_force(int A[], int low, int high, int *ret_low, int *ret_high, int *ret_sum);
int main(void){
    int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    int low, high, sum;

    find_maximum_subarray_brute_force(A, 0, 15, &low, &high, &sum);
    printf("%d %d %d\n", low, high, sum);

    return 0;
}

void find_maximum_subarray_brute_force(int A[], int low, int high, int *ret_low, int *ret_high, int *ret_sum){
    int left, right, sum;
    int max_sum;
    int i, j;

    for(i = 0; i <= high; i++){
        sum = 0;
        for(j = i; j <= high; j++){
            sum += A[j];
            if(j == low || sum > max_sum){
                left = i;
                right = j;
                max_sum = sum;
            }
        }
    }
    *ret_low=left;
    *ret_high=right;
    *ret_sum=max_sum;
}