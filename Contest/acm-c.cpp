#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;
const int MAX_N = 100005;

int n, a[MAX_N];
vector<int> divisors[MAX_N];

int count_subsequences(int x) {
    int count = 0;
    int current = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % x == 0 && a[i] >= x) {
            current++;
            count += current;
            count %= MOD;
        } else {
            current = 0;
        }
    }
    return count;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                divisors[a[i]].push_back(j);
                if (j * j != a[i]) {
                    divisors[a[i]].push_back(a[i] / j);
                }
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int divisor : divisors[a[i]]) {
            answer += count_subsequences(divisor);
            answer %= MOD;
        }
    }

    cout << answer << endl;

    return 0;
}