#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

int compare(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;
    return i1->start - i2->start;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Interval arr[n];

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    qsort(arr, n, sizeof(struct Interval), compare);

    struct Interval result[n];
    int index = 0;

    result[0] = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i].start <= result[index].end) {
            if(arr[i].end > result[index].end)
                result[index].end = arr[i].end;
        } else {
            index++;
            result[index] = arr[i];
        }
    }

    for(int i = 0; i <= index; i++) {
        printf("%d %d\n", result[i].start, result[i].end);
    }

    return 0;
}