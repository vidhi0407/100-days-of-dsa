#include <stdio.h>
#include <stdlib.h>

struct Car {
    int position;
    int speed;
};

int compare(const void *a, const void *b) {
    struct Car *c1 = (struct Car *)a;
    struct Car *c2 = (struct Car *)b;
    return c2->position - c1->position; 
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    struct Car cars[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &cars[i].position);
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    qsort(cars, n, sizeof(struct Car), compare);

    int fleets = 0;
    double prevTime = 0.0;

    for(int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if(time > prevTime) {
            fleets++;
            prevTime = time;
        }
    }

    printf("%d\n", fleets);

    return 0;
}