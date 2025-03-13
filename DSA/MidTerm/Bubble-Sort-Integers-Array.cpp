#include <iostream>
using namespace std;

int main()
{
    // Sorting array of integers and counting step
    char arr[] = "computer_club";
    int sz = 13;

    int pass = 0, step = 0, swaps = 0, steps = 0;
    for (int i = 0; i < sz - 1; i++)
    {
        pass++;
        step = 0;
        cout << "PASS-" << pass << endl;
        bool swapped = false;
        for (int j = 0; j < sz - i - 1; j++)
        {
            step++;
            steps++;
            if (arr[j] > arr[j + 1])
            {
                swaps++;
                cout << "Step-" << step << ": " << arr[j] << ">" << arr[j + 1] << " (Swap)" << " -> ";
                swap(arr[j], arr[j + 1]);
                swapped = true;
                for (int i = 0; i < sz; i++)
                {
                    cout << arr[i];
                }
                cout << endl;
            }
            else
            {
                cout << "Step-" << step << ": " << arr[j] << (arr[j] < arr[j + 1] ? "<" : "=") << arr[j + 1] << " (No Swap)" << endl;
            }
        }
        cout << endl;
        if (!swapped)
        {
            break;
        }
    }

    cout << "Total Pass: " << pass << endl;
    cout << "Total Steps: " << steps << endl;
    cout << "Total Swaps: " << swaps << endl;
}