#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Checks if kth bit of x is set (1) or not (0)
bool k_bit(int x, int k)
{
    return x & (1 << k);
    // return (x >> k) & 1;
}

// Prints the positions of all set (1) bits in binary representation of x
void print_ons(int x)
{
    for (int i = 0; i < 32; i++)
    {
        if (k_bit(x, i))
        {
            cout << i << " ";
        }
    }
}

// Check if x is even or odd
bool even_odd(int x)
{
    return !(x & 1);
}

// Sets the kth bit of x to 1 and returns the result
int setx1(int x, int k)
{
    return x | (1 << k);
}

// Sets the kth bit of x to 0 and returns the result
int setx0(int x, int k)
{
    return x & (~(1 << k));
}

// Toggles the kth bit of x and returns the result
int tooglekbit(int x, int k)
{
    return x ^ (1 << k);
}

// Checks if x is a power of 2
bool powerof2(int x)
{
    int cnt = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((x >> i) & 1)
        {
            cnt++;
        }
    }
    return cnt == 1;
}

int main()
{
    int x = 4; // 10110

    // print_ons(x);

    cout << k_bit(x, 2);

    return 0;
}