#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int currentSum = 0;

    for(int i = 0; i < n; i++) {
        if(arr[i] > maxPages)
            return 0;

        if(currentSum + arr[i] > maxPages) {
            students++;
            currentSum = arr[i];

            if(students > m)
                return 0;
        } else {
            currentSum += arr[i];
        }
    }
    return 1;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    int sum = 0, maxVal = 0;

    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }

    int low = maxVal;
    int high = sum;
    int result = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;  
        } else {
            low = mid + 1;
        }
    }

    printf("%d\n", result);

    return 0;
}