//22
#include <stdio.h>

int count(int arr[], int n, int query) {
    int left = 0, right = n - 1, result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= query) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result + 1;
}

int main() {
    int n, m;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int query;
        scanf("%d", &query);
        printf("%d\n", count(arr, n, query));
    }
    return 0;
}
