#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e7 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int some_prime[MAX] = {0};
    for (int i = 2; i < MAX; i++)
        if (!some_prime[i])
            for (int j = i; j < MAX; j += i)
                some_prime[j] = i;

    int n; cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;

        if (gcd(x, y) > 1) cout << "0\n";
        else if (y - x == 1) cout << "-1\n";
        else {
            int mn = INT_MAX, diff = y - x;
            while (diff > 1) {
                mn = min(mn, x + some_prime[diff] - (x + some_prime[diff]) % some_prime[diff]);
                diff /= some_prime[diff];
            }

            int ans = mn - x;
            cout << ans << "\n";
        }
    }
}