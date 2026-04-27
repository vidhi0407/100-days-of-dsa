#include <stdio.h>

int integerSquareRoot(int n) {
    int low = 0, high = n, ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long square = (long long)mid * mid;

        if (square == n) {
            return mid;  
        else if (square < n) {
            ans = mid;      
            low = mid + 1;  
        } 
        else {
            high = mid - 1; 
        }
    }

    return ans; 
}

int main() {
    int n;
    scanf("%d", &n);

    int result = integerSquareRoot(n);
    printf("%d\n", result);

    return 0;
}