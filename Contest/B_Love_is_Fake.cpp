#include <bits/stdc++.h>
using namespace std;

int sumOfDivisors(int n) {
    int sum = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i + (n / i);
            if (i * i == n) {
                sum -= i;
            }
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;

        int first = sumOfDivisors(x);
        if (first - x != y) {
            cout << "Friendship is not ideal" << endl;
            continue;
        }

        int second = sumOfDivisors(y);
        if (second - y != x) {
            cout << "Friendship is not ideal" << endl;
        } else {
            cout << "Friendship is ideal" << endl;
        }
    }

    return 0;
}