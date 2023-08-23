#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Structure for the hash table
struct HashTable {
    int keys[SIZE];
    int values[SIZE];
};

// Function to initialize the hash table
void initializeHashTable(struct HashTable *hashTable) {
    for (int i = 0; i < SIZE; i++) {
        hashTable->keys[i] = -1; // -1 indicates an empty slot
        hashTable->values[i] = -1;
    }
}

// Hash function to calculate the index for a given key
int hashFunction(int key) {
    return key % SIZE;
}

// Function to insert a key-value pair into the hash table using linear probing
void insert(struct HashTable *hashTable, int key, int value) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable->keys[index] != -1) {
        index = (index + 1) % SIZE; // Move linearly to the next slot
        if (index == originalIndex) {
            printf("Hash table is full. Cannot insert.\n");
            return;
        }
    }

    hashTable->keys[index] = key;
    hashTable->values[index] = value;
}

// Function to search for a value using its key
int search(struct HashTable *hashTable, int key) {
    int index = hashFunction(key);
    int originalIndex = index;

    while (hashTable->keys[index] != -1) {
        if (hashTable->keys[index] == key) {
            return hashTable->values[index];
        }
        index = (index + 1) % SIZE; // Move linearly to the next slot
        if (index == originalIndex) {
            break;
        }
    }

    return -1; // Key not found
}

int main() {
    struct HashTable hashTable;
    initializeHashTable(&hashTable);

    insert(&hashTable, 5, 50);
    insert(&hashTable, 15, 150);
    insert(&hashTable, 25, 250);

    int keyToSearch = 15;
    int value = search(&hashTable, keyToSearch);
    if (value != -1) {
        printf("Value for key %d: %d\n", keyToSearch, value);
    } else {
        printf("Value for key %d not found.\n", keyToSearch);
    }

    return 0;
}

