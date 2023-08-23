#include <stdio.h>

#define MAX_SIZE 100

// Function to display the elements of the array
void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element at a specified position
int insert(int arr[], int size, int element, int position) {
    if (size >= MAX_SIZE) {
        printf("Array is full. Insertion not possible.\n");
        return size;
    }

    if (position < 0 || position > size) {
        printf("Invalid position for insertion.\n");
        return size;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;

    return size + 1;
}

// Function to delete an element from a specified position
int deleteElement(int arr[], int size, int position) {
    if (size <= 0) {
        printf("Array is empty. Deletion not possible.\n");
        return size;
    }

    if (position < 0 || position >= size) {
        printf("Invalid position for deletion.\n");
        return size;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    int choice, element, position;

    do {
        printf("\nArray Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                size = insert(arr, size, element, position);
                break;

            case 2:
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                size = deleteElement(arr, size, position);
                break;

            case 3:
                display(arr, size);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);

    return 0;
}

