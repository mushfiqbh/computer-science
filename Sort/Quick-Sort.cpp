#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high)
{
    int c = low;
    int pv = arr[high];
    int i;

    for (i = low; i < high; i++)
    {
        if (arr[i] < pv)
        {
            swap(arr[i], arr[c]);
            c++;
        }
    }
    swap(arr[c], arr[i]);
    return c;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pv = partition(arr, low, high);
        quick_sort(arr, low, pv - 1);
        quick_sort(arr, pv + 1, high);
    }
}

int main()
{
    int n = 10;
    int arr[n] = {3, 6, 2, 96, 2, 45, 50, 44, 90, 5};

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}