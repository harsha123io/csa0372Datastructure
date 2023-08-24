#include <stdio.h>
int main() {
    int n, a = 0, b = 1, next, sum = 0;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    printf("Fibonacci Series: %d, %d, ", a, b);
    for (int i = 3; i <= n; ++i) {
        next = a + b;
        sum += next;
        printf("%d, ", next);
        a = b;
        b = next;
    }
    printf("\nSum of Fibonacci Series: %d\n", sum);
    return 0;
}