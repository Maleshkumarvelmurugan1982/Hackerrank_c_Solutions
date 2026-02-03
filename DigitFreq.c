#include <stdio.h>
#include <string.h>
int main() {
    char input[1000]; 
    int count[10] = {0}; 
    scanf("%s", input);
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            count[input[i] - '0']++;
        }
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    return 0;
}
