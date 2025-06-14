#include <iostream>
using namespace std;

void counting_sort(int A[], int n){
    int max_val = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max_val) {
            max_val = A[i];
        }
    }

    int duplicate[max_val + 1] = {0};
    for (int i = 0; i < n; i++) {
        duplicate[A[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (duplicate[i] > 0) {
            A[index++] = i;
            duplicate[i]--;
        }
    }
}

void display(int A[], int n) {
    int i = 0;
    while (i < n) {
        cout << A[i] << " ";
        i++;
    }
    cout << endl;
}

int main() {
    int arr[] = {4, 6, 2, 9, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    counting_sort(arr, size);
    display(arr, size);
    return 0;
}
