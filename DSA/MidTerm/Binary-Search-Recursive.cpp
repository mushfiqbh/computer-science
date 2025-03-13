#include <iostream>
using namespace std;

bool BinarySearchRecursion(int arr[], int low, int high, int key)
{
    if (low > high) // Base Case
    {
        return false; // Item Not Found
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key) // Item Found
    {
        return true;
    }
    else if (arr[mid] < key)
    {
        low = mid + 1;
        BinarySearchRecursion(arr, low, high, key);
    }
    else
    {
        high = mid - 1;
        BinarySearchRecursion(arr, low, high, key);
    }
}

int main()
{
    int key;
    cin >> key;

    int arr[10] = {1, 3, 4, 8, 9, 10, 33, 35};
    int n = sizeof(arr) / sizeof(int);
    int low = 0;
    int high = n - 1;

    // Recursion Binary Search
    if (BinarySearchRecursion(arr, low, high, key))
    {
        cout << "Found By Recursion" << endl;
    }
    else
    {
        cout << "NOT Found By Recursion" << endl;
    }
}