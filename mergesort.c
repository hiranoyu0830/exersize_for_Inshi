//5/22 らせん本　p.152 mergesort

#include<stdio.h>
#define MAX 100000
#define SENTINEL    200000000
#define rep(i,n) for (int i = 0; i < (n); ++i)

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt;

void merge(int A[], int n, int left, int mid, int right) {
    int n1 = mid -left;
    int n2 = right - mid;
    rep(i,n1) L[i] = A[left+i];
    rep(i,n2) R[i] = A[mid+i];
    L[n1] = R[n2] = SENTINEL;
    int i=0, j=0;
    for (int k=left; k<right; k++) {
        cnt++;
        if ( L[i]<=R[j]) {
            A[k] = L[i++];
        }else{
            A[k] = R[j++];
        }
    }
}

void mergeSort(int A[], int n, int left, int right) {
    if (left+1 < right) {
        int mid = (left + right)/2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main() {

    int A[MAX], n, i;
    cnt = 0;

    scanf("%d\n", &n);
    rep(i,n) scanf("%d", &A[i]);

    mergeSort(A,n,0,n);

    rep(i,n) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d", cnt);
    return 0;    
}