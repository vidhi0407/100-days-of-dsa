#include <stdio.h>
#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    if (size == MAX) {
        return;
    }
    pq[size++] = x;
}

int findMinIndex() {
    if (size == 0) return -1;

    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int deleteMin() {
    if (size == 0) return -1;

    int minIndex = findMinIndex();
    int val = pq[minIndex];

    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;
    return val;
}

int peek() {
    if (size == 0) return -1;

    int minIndex = findMinIndex();
    return pq[minIndex];
}

int main() {
    int n;
    scanf("%d", &n);

    char op[10];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (op[0] == 'i') { 
            scanf("%d", &x);
            insert(x);
        }
        else if (op[0] == 'd') { 
            printf("%d\n", deleteMin());
        }
        else if (op[0] == 'p') { 
            printf("%d\n", peek());
        }
    }

    return 0;
}