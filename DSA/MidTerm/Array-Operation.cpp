#include<iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size/capacity of the array

int main()
{

    int arr[MAX_SIZE];
    int size = 0;

    // Example usage:
    insertAtEnd(arr, size, 10);
    insertAtEnd(arr, size, 20);
    insertAtEnd(arr, size, 30);
    traverse(arr, size);

    insertAtPos(arr, size, 1, 15);
    traverse(arr, size);

    insertAtBeg(arr, size, 5);
    traverse(arr, size);

    deleteFromEnd(arr, size);
    traverse(arr, size);

    deleteFromPos(arr, size, 1);
    traverse(arr, size);

    deleteFromBeg(arr, size);
    traverse(arr, size);

    return 0;
    
    int arr[10] = {10, 20, 30, 40, 50};
    int pos = 2, val = 25, sz = 5;

    // insert element at position pos
    for (int i = sz - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = val;
    sz++;

    // print array elements
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // delete element at position pos
    for (int i = pos; i < sz - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    sz--;

    // print array elements
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
#include <iostream>
using namespace std;
const int MAX_SIZE = 100; // Maximum size of the array

// Function to insert an element at the end of the array
void insertAtEnd(int arr[], int &size, int element) {
    if (size >= MAX_SIZE) {
        cout << "Array overflow!" << endl;
        return;
    }
    arr[size++] = element;
}

// Function to insert an element at a given position
void insertAtPos(int arr[], int &size, int pos, int element) {
    if (size >= MAX_SIZE) {
        cout << "Array overflow!" << endl;
        return;
    }
    if (pos < 0 || pos > size) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements to the right
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = element;
    size++;
}

// Function to insert an element at the beginning of the array
void insertAtBeg(int arr[], int &size, int element) {
    if (size >= MAX_SIZE) {
        cout << "Array overflow!" << endl;
        return;
    }

    // Shift elements to the right
    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = element;
    size++;
}

// Function to delete an element from the end of the array
void deleteFromEnd(int arr[], int &size) {
    if (size == 0) {
        cout << "Array underflow!" << endl;
        return;
    }
    size--;
}

// Function to delete an element from a given position
void deleteFromPos(int arr[], int &size, int pos) {
    if (size == 0) {
        cout << "Array underflow!" << endl;
        return;
    }
    if (pos < 0 || pos >= size) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Shift elements to the left
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Function to delete an element from the beginning of the array
void deleteFromBeg(int arr[], int &size) {
    if (size == 0) {
        cout << "Array underflow!" << endl;
        return;
    }

    // Shift elements to the left
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}

// Function to traverse and print the array
void traverse(int arr[], int size) {
    if (size == 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

*/