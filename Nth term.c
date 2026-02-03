#include <stdio.h>

int find_nth_term(int n, int a, int b, int c) {
    if (n == 1) return a;
    if (n == 2) return b;
    if (n == 3) return c;

    int prev1 = a, prev2 = b, prev3 = c, current;
    for (int i = 4; i <= n; i++) {
        current = prev1 + prev2 + prev3;
        prev1 = prev2;
        prev2 = prev3;
        prev3 = current;
    }
    return current;
}

int main() {
    int n, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
    printf("%d\n", ans);
    return 0;
}
