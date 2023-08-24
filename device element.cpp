#include <stdio.h>

int main() {
    int n, element, found = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &element);
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Element %d is present in the array.\n", element);
    } else {
        printf("Element %d is not present in the array.\n", element);
    }
     return 0;
}
