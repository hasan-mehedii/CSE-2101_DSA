#include <iostream>
using namespace std;

void bubble_sort(int A[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(A[i]>A[j]){
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
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
    
    bubble_sort(arr, size);
    display(arr, size);
    return 0;
}