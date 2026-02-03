#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int size = 2 * n - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int top = i;
            int left = j;
            int bottom = size - 1 - i;
            int right = size - 1 - j;
            int min_dist = top;
            if (left < min_dist)
                min_dist = left;
            if (bottom < min_dist)
                min_dist = bottom;
            if (right < min_dist)
                min_dist = right;
            printf("%d ", n - min_dist);
        }
        printf("\n");
    }
    return 0;
}
