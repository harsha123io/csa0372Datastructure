#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of terms in Fibonacci series: ");
    scanf("%d", &n);

    int first = 0, second = 1;

    printf("Fibonacci series:\n");
    printf("%d\n%d\n", first, second);

    for (int i = 2; i < n; i++) {
        int next = first + second;
        printf("%d\n", next);
        first = second;
        second = next;
    }

    return 0;
}

