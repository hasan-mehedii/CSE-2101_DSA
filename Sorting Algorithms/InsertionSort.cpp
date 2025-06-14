#include <iostream>
using namespace std;

void insertion_sort(int A[], int n){
    int temp;
    for(int i=0; i<n; i++){
        temp = A[i];
        int j = i - 1;
        while(j>=0 && A[j]>temp){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=temp;
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
    
    insertion_sort(arr, size);
    display(arr, size);
    return 0;
}