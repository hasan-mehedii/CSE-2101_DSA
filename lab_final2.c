//22
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int mark;
} Node;

int compare(const void *a, const void *b) {
    Node *n1 = (Node *)a;
    Node *n2 = (Node *)b;
    
    if (n1->mark != n2->mark) {
        return n1->mark - n2->mark;
    }
    return n1->id - n2->id;
}

int main() {
    int n;
    scanf("%d", &n);
    
    Node *arr = (Node *)malloc(n * sizeof(Node));
    if (!arr) return 1;
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].id, &arr[i].mark);
    }
    
    qsort(arr, n, sizeof(Node), compare);
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i].id);
    }
    
    free(arr);
    return 0;
}
