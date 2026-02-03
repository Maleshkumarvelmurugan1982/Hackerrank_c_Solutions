#include <stdio.h>
#include <string.h>
int main() {
    char ch;
    char s[100];
    char sen[1000];

    // Read the character
    scanf("%c", &ch);
    getchar();

    
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';


    fgets(sen, sizeof(sen), stdin);
    sen[strcspn(sen, "\n")] = '\0'; 

    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);

    return 0;
}
