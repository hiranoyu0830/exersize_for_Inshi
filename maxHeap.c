#include<stdio.h>
#define MAX 100000
#define rep(i,n) for (int i = 0; i < (n); ++i)

int H, A[MAX+1];

void maxHeapify(int i){
    int l, r, largest, tmp;
    l = 2*i;
    r = 2*i + 1;
    if (l <= H && A[l] > A[i]) largest = l;
    else largest = i;
    if ( r <= H && A[r]>A[largest]) largest =  r;

    if (largest!=i) {
        tmp = A[largest]; A[largest] = A[i]; A[i] = tmp;
        maxHeapify(largest);
    }
    
}

int main() {
    int i;

    scanf("%d", &H);
    for(i=1; i<=H; i++) {
        scanf("%d", &A[i]);
    }

    for(i=H/2; i>=1; i--) maxHeapify(i);

    for(i=1; i<=H; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}