#include <stdio.h>
void genComb(int n, int k, int start, int currComb[], int index) {
    if (index == k) {
        for (int i = 0; i < k; i++) {
            printf("%d ", currComb[i]);
        }
        printf("\n");
        return;
    }
    for (int i = start; i >= 0; i--) {
        currComb[index] = i;
        genComb(n, k, i - 1, currComb, index + 1);
    }
}
int main() {
    int n, k;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter k: ");
    scanf("%d", &k);

    int currComb[k];
    genComb(n, k, n - 1, currComb, 0);
    return 0;
}



