#include <iostream>
using namespace std;

int main()
{
    // Sorting Your Phone Number
    int phone = 1737542444;
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = phone % 10;
        phone = phone / 10;
    }
    int sz = sizeof arr / sizeof(int);

    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << " ";
    }
}