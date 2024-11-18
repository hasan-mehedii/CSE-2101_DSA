#include <iostream>
using namespace std;

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for(int i=0; i<n1; i++){
        L[i] = A[left+i];
    }
    for(int j=0; j<n2; j++){
        R[j] = A[mid+1+j];
    }
    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k]=R[j];
        j++;
        k++;
    }
}

void merge_sort(int A[], int left, int right){
    if(left<right){
        int mid = left + (right-left)/2;
        merge_sort(A, left, mid);
        merge_sort(A, mid+1, right);

        merge(A, left, mid, right);
    }
}

void display(int A[], int n){
    int i = 0;
    while(i < n){
        cout<<A[i]<<endl;
        i++;
    }
}

int main(){
    int arr[] = {4, 6, 2, 9, 5, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    merge_sort(arr, 0, size-1);
    display(arr, size);
    return 0;
}