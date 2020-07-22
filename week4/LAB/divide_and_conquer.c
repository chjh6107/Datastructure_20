#include <stdio.h>

void find_maximum_subarray(int A[], int low, int high, int *ret_low, int *ret_high, int *ret_sum);
void find_max_crossing_subarray(int A[], int low, int mid, int high, int *ret_low, int *ret_high, int *ret_sum);

int main(void){
    int A[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    int low, high, sum;

    find_maximum_subarray(A, 0, 15, &low, &high, &sum);
    printf("%d %d %d\n", low, high, sum);

    return 0;
}

void find_maximum_subarray(int A[], int low, int high, int *ret_low, int *ret_high, int *ret_sum){
    int left_low, left_high, left_sum;
    int right_low, right_high, right_sum;
    int cross_low, cross_high, cross_sum;
    int mid;

    if(high == low){
        *ret_low = low;
        *ret_high = high;
        *ret_sum = A[low];
        return;
    }else{
        mid = (low + high) / 2;
        find_maximum_subarray(A, low, mid, &left_low, &left_high, &left_sum);
        find_maximum_subarray(A, mid+1, high, &right_low, &right_high, &right_sum);
        find_max_crossing_subarray(A, low, mid, high, &cross_low, &cross_high, &cross_sum);
    
        if(left_sum >= right_sum && left_sum >= cross_sum){
            *ret_low = left_low;
            *ret_high = left_high;
            *ret_sum = left_sum;
        }
        else if(right_sum >= left_sum && right_sum >= cross_sum){
            *ret_low = right_low;
            *ret_high = right_high;
            *ret_sum = right_sum;
        }
        else{
            *ret_low = cross_low;
            *ret_high = cross_high;
            *ret_sum = cross_sum;
        }
    }
}
void find_max_crossing_subarray(int A[], int low, int mid, int high, int *ret_low, int *ret_high, int *ret_sum){
    int left_sum, right_sum;
    int sum;
    int max_left, max_right;
    int i;

    left_sum = -100000; //minus infinite
    sum =0;

    for(i = mid; i >= low; i--){
        sum += A[i];
        if(sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }

    right_sum = -100000; //minus infinite
    sum = 0;

    for(i = mid + 1; i <= high; i++){
        sum += A[i];
        if(sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }
    *ret_low = max_left;
    *ret_high = max_right;
    *ret_sum = left_sum + right_sum;
}