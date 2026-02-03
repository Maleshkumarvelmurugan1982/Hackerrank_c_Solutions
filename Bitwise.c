#include <stdio.h>

void calculate_the_maximum(int n, int k) {
    int maxAnd = 0;
    int maxOr = 0;
    int maxXor = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int andVal = i & j;
            int orVal = i | j;
            int xorVal = i ^ j;

            if (andVal > maxAnd && andVal < k)
                maxAnd = andVal;

            if (orVal > maxOr && orVal < k)
                maxOr = orVal;

            if (xorVal > maxXor && xorVal < k)
                maxXor = xorVal;
        }
    }

    printf("%d\n", maxAnd);
    printf("%d\n", maxOr);
    printf("%d\n", maxXor);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
    return 0;
}
