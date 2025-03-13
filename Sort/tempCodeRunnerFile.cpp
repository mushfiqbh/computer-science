#include <bits/stdc++.h>
using namespace std;

const int n = 10;
int arr[n] = {3, 5, 2, 4, 5, 3, 3, 5, 2, 9};
int temp[n];

void Merge(int L, int Mid, int H)
{
    int i = L;
    int j = Mid + 1;
    int k = L;

    while(i <= Mid && j <= H)
    {
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    for (i; i <= Mid; i++)
    {
        temp[k] = arr[i];
        k++;
    }

    
    for (j; j <= H; j++)
    {
        temp[k] = arr[j];
        k++;
    }

    for(int m = L; m <= H; m++){
        arr[m] = temp[m];
    }
}

void MergeSort(int start, int end)
{
    if (start < end)
    {
        int mid = (end + start) / 2;
        MergeSort(start, mid);
        MergeSort(mid + 1, end);
        Merge(start, mid, end);
    }
}

int main()
{
    MergeSort(0, n - 1);

    cout << "Descending ordered array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}