#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class MyInt
{
public:
    explicit MyInt(int *p = nullptr) { data = p; }
    ~MyInt() { delete data; };
    int &operator*() { return *data; }

private:
    int *data;
};

int main()
{
    int *p = new int(10);
    MyInt myInt = MyInt(p);

    cout << *myInt;

    return 0;
}