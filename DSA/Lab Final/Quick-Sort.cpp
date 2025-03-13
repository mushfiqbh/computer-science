// Quick Sort
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int p = start + 1;
    int q = end;

    while (p <= q)
    {
        while (arr[p] <= pivot)
        {
            p++;
        }
        while (arr[q] > pivot)
        {
            q--;
        }
        if (p < q)
        {
            swap(arr[p], arr[q]);
        }
    }

    swap(arr[start], arr[q]);
    return q;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int loc = partition(arr, start, end);
        quickSort(arr, start, loc - 1);
        quickSort(arr, loc + 1, end);
    }
}

int main()
{
    int arr[] = {10, 5, 2, 15, 10, 22, 11, 7, 3, 17};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
