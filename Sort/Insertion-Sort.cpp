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

    // i for each elements of the array
    for (int i = 1; i < n; i++)
    {
        int current = arr[i]; // take arr[i] to current
        // j for every precedents of i
        int j = i - 1; // first precedent of i
        while (arr[j] < current && j >= 0)
        {
            arr[j + 1] = arr[j]; // slide to right all precedents that less than current
            j--;                 // update j to next precedent
        }
        // set current to the empty space where it's last precedent slided right
        arr[j + 1] = current;
    }

    cout << "Descending ordered array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}