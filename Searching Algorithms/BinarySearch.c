#include <stdio.h>

int binary_search(int A[], int target, int low, int high){
    if(low>high){
        return -1;
    }
    int mid = (low+high)/2;

    if(A[mid] == target){
        return mid;
    }
    else if(A[mid]>target){
        return binary_search(A, target, low, mid-1);
    }
    else{
        return binary_search(A, target, mid+1, high);
    }
}

int main(){
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 5;
    int low = 0, high = sizeof(arr)/sizeof(arr[0]);
    
    int result = binary_search(arr, target, low, high);
    printf("Found at index: %d\n", result);
    return 0;
}