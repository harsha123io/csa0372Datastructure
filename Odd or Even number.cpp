#include <stdio.h>

int main() {
    int numCount;

    printf("Enter the number of elements: ");
    scanf("%d", &numCount);

    printf("Enter %d numbers:\n", numCount);
    for (int i = 0; i < numCount; i++) {
        int number;
        scanf("%d", &number);

        if (number % 2 == 0) {
            printf("%d is even.\n", number);
        } else {
            printf("%d is odd.\n", number);
        }
    }

    return 0;
}

