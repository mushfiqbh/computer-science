#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <numeric>
#include <algorithm>
using namespace std;

int main()
{
    list<int> li(10);
    iota(li.begin(), li.end(), 1);
    for(auto x : li) cout << x << " ";
    cout << endl;

    vector<int> from_vector = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> to_vector;
    // copy(from_vector.begin(), from_vector.end(), to_vector.begin());
    copy_if(from_vector.begin(), from_vector.end(), back_inserter(to_vector), [](int x){ return x % 2 == 0; }); // back inserter
    for(auto x : to_vector) cout << x << " ";
    cout << endl;

    
    vector<int> copyn;
    // Copy N
    copy_n(from_vector.begin(), 5, back_inserter(copyn));
    for(auto x : copyn) cout << x << " ";
    cout << endl;

    vector<int> copyback(10);
    // Copy Backward
    copy_backward(from_vector.begin(), from_vector.end(), copyback.end());
    for(auto x : copyback) cout << x << " ";
    cout << endl;


    return 0;
}