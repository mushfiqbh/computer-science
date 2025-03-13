#include <iostream>
using namespace std;

bool isLuckyNum(int num) {
    while (num > 0) {
        int digit = num % 10;
        if (digit != 4 && digit != 7) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    int a, b;
    cin >> a >> b;

    bool foundLucky = false;
    for (int i = a; i <= b; i++) {
        if (isLuckyNum(i)) {
            foundLucky = true;
            cout << i << " ";
        }
    }

    if (!foundLucky) {
        cout << -1;
    }
    
    return 0;
}