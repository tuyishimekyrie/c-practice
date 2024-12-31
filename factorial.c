#include <stdio.h>

int factorialIterative(int n);

int main() {
    int n;
    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial of a negative number is undefined.\n");
    } else {
        printf("Factorial of %d is %d\n", n, factorialIterative(n));
    }

    return 0;
}

int factorialIterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}
