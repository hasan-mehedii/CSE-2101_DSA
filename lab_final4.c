//22
//22
#include <stdio.h>

void genLists(int n, int curr[], int index) {
    if (index == n) {
        for (int i = 0; i < n; i++) {
            printf("%d", curr[i]);
            if (i < n - 1) printf(" ");
        }
        printf("\n");
        return;
    }
    
    if (index % 2 == 0) { // Even index (0-based) -> Even digits (0, 2, 4)
        for (int i = 0; i <= 4; i += 2) {
            curr[index] = i;
            genLists(n, curr, index + 1);
        }
    } else { // Odd index (0-based) -> Odd digits (1, 3)
        for (int i = 1; i <= 3; i += 2) {
            curr[index] = i;
            genLists(n, curr, index + 1);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int curr[n];
    genLists(n, curr, 0);
    return 0;
}
