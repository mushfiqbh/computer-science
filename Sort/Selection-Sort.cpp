#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter array length: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // i for each elements belongs to sorted subarray
    for (int i = 0; i < n; i++)
    {
        // j for rest of the array belongs to unsorted subarray
        for (int j = i + 1; j < n; j++)
        {
            // if i'th & j'th value in ascending order, swap them
            if (arr[i] < arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }

    cout << "Descending ordered array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}