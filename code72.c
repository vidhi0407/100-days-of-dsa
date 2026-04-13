#include <stdio.h>
#include <string.h>

#define SIZE 26

int main() {
    char s[1000];
    scanf("%s", s);

    int firstIndex[SIZE];

    for (int i = 0; i < SIZE; i++) {
        firstIndex[i] = -1;
    }

    int minSecondIndex = 100000;
    char result = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        int idx = s[i] - 'a';

        if (firstIndex[idx] == -1) {
            firstIndex[idx] = i;  
        } 
        else {
            if (i < minSecondIndex) {
                minSecondIndex = i;
                result = s[i];
            }
        }
    }

    if (result == -1) {
        printf("-1");
    } else {
        printf("%c", result);
    }

    return 0;
}