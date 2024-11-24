#include <stdio.h>

typedef struct storage Store;

struct storage{
    int n1;
    int n2;
};

int main(){
    int n;
    scanf("%d",&n);
    
    Store arr[n];
    for(int i=0; i<n; i++){
        scanf("%d%d",&arr[i].n1, &arr[i].n2);
    }

    //Inserton Sort
    for (int i=1; i<n; i++){
        Store key=arr[i];
        int j=i-1;

        while (j>=0 && (arr[j].n1>key.n1 || (arr[j].n1==key.n1 && arr[j].n2>key.n2))){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    for(int i=0; i<n; i++){
        printf("%d %d\n",arr[i].n1, arr[i].n2);
    }
    return 0;
}

/*
input:
-------
4
2 3
4 5
2 1
3 4

expected output:
----------------
2 1
2 3
3 4
4 5
*/