#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1
#define DELETED -2

int *table;
int m;

int hash(int key) {
    return key % m;
}

void insert(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY || table[idx] == DELETED) {
            table[idx] = key;
            return;
        }
    }
}

int search(int key) {
    int h = hash(key);

    for (int i = 0; i < m; i++) {
        int idx = (h + i * i) % m;

        if (table[idx] == EMPTY) {
            return 0; 
        }

        if (table[idx] == key) {
            return 1;
        }
    }
    return 0;
}

int main() {
    scanf("%d", &m);

    int n;
    scanf("%d", &n);

    table = (int*)malloc(sizeof(int) * m);

    for (int i = 0; i < m; i++) {
        table[i] = EMPTY;
    }

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (op[0] == 'I') {
            insert(key);
        }
        else if (op[0] == 'S') {
            if (search(key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }

    free(table);
    return 0;
}