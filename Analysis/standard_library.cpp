#include <bits/stdc++.h>
using namespace std;

int increment(int x) { return (x + 1); }

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    /**
     * Loop over each element and change each value
     * of arr by a defined function
     * and save in the original arr
     */
    transform(arr, arr + n, arr, increment);

    int *ptr;
    ptr = &arr[0];

    /**
     * Change the ptr pointed arr[0]
     * to arr[0+2]
     * advance() overwrite original pointer
     * next() or prev() create new pointer iterator
     */
    advance(ptr, 2);
    auto it = next(ptr, 2);
    auto it2 = prev(ptr, 2);
    cout << *ptr << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    /**
     * Pair
     */
    pair<int, double> pair0(12, 34.5);
    pair<string, int> pair1;
    pair1.first = "Hi";
    pair1.second = 20;
    pair<string, int> pair2("Okay", 30);
    // pair3 = make_pair("Okay", 30);
    pair1.swap(pair2);
    cout << pair1.first;

    


    return 0;
}
