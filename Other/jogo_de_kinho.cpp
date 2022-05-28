#include <bits/stdc++.h>

using namespace std;

#define long long long int

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x; cin >> x;

    if (x == 1) {
        cout << "no\n";
        return 0;
    }

    map<int, int> factors;
    for (long i = 2LL; i * i <= x; i++)
        while (x % i == 0) {
            factors[i]++;
            x /= i;
        }

    if (x > 1) factors[x]++;

    int ans = 0;
    for (auto [prime, exponent]: factors)
        ans ^= exponent;

    cout << (ans ? "yes" : "no") << "\n";
}