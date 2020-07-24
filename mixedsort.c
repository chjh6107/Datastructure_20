#include <stdio.h>
#include <stdlib.h>

void st_inout(){
    char st_name[3][10];
    int st_num[3];
    char st_school[3][20];

    for(int i=0;i<3;i++){
        printf("이 름 : ");
        scanf("%s",st_name[i]);
        printf("학 교 : ");
        scanf("%s",st_school[i]);
        printf("학 번 : ");
        scanf("%d",&st_num[i]);
    }
    for(int i = 0;i<3;i++){
        printf("이 름 : %s\t학 교 : %s\t학 번 : %d\n",st_name[i],st_school[i],st_num[i]);
    }
}

void merge(int A[], int p, int q, int r) {
    int *tmpL, *tmpR; //L, R
    int boundary; //Infinity
    int n1, n2;
    int i, j, k;

    n1 = q - p + 1;
    n2 = r - q;

    tmpL = (int*)malloc(sizeof(int) * (n1 + 1));
    tmpR = (int*)malloc(sizeof(int) * (n2 + 1));

    for (i = 0; i < n1; i++) tmpL[i] = A[p + i];
    for (j = 0; j < n2; j++) tmpR[j] = A[q + j + 1];

    boundary = tmpL[n1 - 1] > tmpR[n2 - 1] ? tmpL[n1 - 1] + 1 : tmpR[n2 - 1] + 1; //Infinity
    tmpL[n1] = boundary;
    tmpR[n2] = boundary;

    i = 0;
    j = 0;

        for(k = p; k <= r; k++){
            if(tmpL[i] <= tmpR[j]){
                A[k] = tmpL[i];
                i = i + 1;
            }
            else{
                A[k] = tmpR[j];
                j = j + 1;
            }
        }





    free(tmpL);
    free(tmpR);
}

void merge_sort(int A[], int p, int r){
    int q;

    if(p < r){
        q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void sort3(){
    int A1[8]={}, B1[6]={}, C1[14]={};
    int temp;
    for(int i = 0;i<8;i++){
        printf("A1[%d] 입력 : ",i);
        scanf("%d",&A1[i]);
    }
    
    for(int i=0;i<6;i++){
        printf("B1[%d] 입력 : ", i);
        scanf("%d",&B1[i]);
    }

//////////선택정렬/////////////
    for(int i = 0; i<7; i++){
        for(int j = i+1; j<8;j++){
            if(A1[i]>A1[j]){
                temp=A1[i];
                A1[i]=A1[j];
                A1[j]=temp;
            }
        }
    }
    // for(int i = 0;i<8;i++) printf("%d ",A1[i]);

///////////버블정렬/////////
    for(int i = 1; i<6;i++){
        for(int j =0; j<6-i;j++){
            if(B1[j]>B1[j+1]){
                temp = B1[j];
                B1[j] = B1[j+1];
                B1[j+1]=temp;                
            }
        }
    }

    for(int i=0;i<14;i++){
        if(i<8)
            C1[i]=A1[i];
        else
            C1[i]=B1[i-8];
    }
    merge_sort(C1, 0, 13);
    for(int i = 0; i<14;i++) printf("%d ",C1[i]);
    
}

int main(){

    int num;

    // st_inout();
    sort3();
   
    return 0;
}