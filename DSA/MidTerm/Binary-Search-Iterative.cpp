#include <iostream>
using namespace std;

void BinarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == key)
        {
            cout << "Found in Binary Search" << endl;
            return;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "NOT found in Binary search" << endl;
}

int main()
{
    int key;
    cin >> key;

    int arr[10] = {1, 3, 4, 8, 9, 10, 33, 35};
    int n = sizeof(arr) / sizeof(int);
    int low = 0;
    int high = n - 1;

    // Call the Binary Search Function
    BinarySearch(arr, low, high, key);
}