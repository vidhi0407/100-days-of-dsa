#include <stdio.h>

int isPossible(int boards[], int n, int k, int maxTime) {
    int painters = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(boards[i] > maxTime)
            return 0;

        if(currentSum + boards[i] > maxTime) {
            painters++;
            currentSum = boards[i];

            if(painters > k)
                return 0;
        } else {
            currentSum += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int sum = 0, maxVal = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if(boards[i] > maxVal)
            maxVal = boards[i];
    }

    int low = maxVal;
    int high = sum;
    int result = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1;  
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", result);

    return 0;
}