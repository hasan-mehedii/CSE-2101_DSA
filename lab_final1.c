//22
//22
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int countFrequency(int arr[], int n, int key) {
    int *found = (int *)bsearch(&key, arr, n, sizeof(int), compare);
    if (found == NULL) {
        return 0;
    }

    int index = found - arr;
    
    int count = 1, i = index - 1, j = index + 1;
    
    while (i >= 0 && arr[i] == key) {
        count++;
        i--;
    }
    
    while (j < n && arr[j] == key) {
        count++;
        j++;
    }

    return count;
}

int main() {
    int n, m;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    qsort(arr, n, sizeof(int), compare);

    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int query;
        scanf("%d", &query);
        printf("%d\n", countFrequency(arr, n, query));
    }

    free(arr);
    return 0;
}
