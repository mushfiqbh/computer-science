// Author: Mushfiq R.
#include <iostream>
#include <algorithm>
#define ll long long
#define ld long double
#define ull unsigned long long
#define vsort(v) sort(v.begin(), v.end())
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL));
using namespace std;

int main()
{
    fastread();
    ll a, b, c;
    char s, q;
    cin >> a >> s >> b >> q >> c;

    if(s == '+'){
        if(a + b == c){
            cout << "YES";
        }else{
            cout << a + b;
        }
    }else if(s == '-'){
        if(a - b == c){
            cout << "YES";
        }else{
            cout << a - b;
        }
    }else if(s == '*'){
        if(a * b == c){
            cout << "YES";
        }else{
            cout << a * b;
        }
    }

    return 0;
}