#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	int i = n - 2;
    while (i >= 0 && strcmp(s[i], s[i + 1]) >= 0) {
        i--;
    }
    if (i < 0) {
        return 0;
    }
    int j = n - 1;
    while (strcmp(s[j], s[i]) <= 0) {
        j--;
    }
    char *temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    int left = i + 1;
    int right = n - 1;
    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
    return 1;
}

