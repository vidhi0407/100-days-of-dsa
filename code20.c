#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefix = 0;
    int count = 0;

    int hash[2 * MAX + 1] = {0};

    int offset = MAX;

    hash[offset] = 1; 

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        count += hash[prefix + offset];

        hash[prefix + offset]++;
    }

    printf("%d", count);

    return 0;
}