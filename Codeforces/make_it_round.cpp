#include <bits/stdc++.h>

using namespace std;

#define llong long long int

int count_factors(int n, int factor) {
    int ans = 0;
    while (n % factor == 0) {
        ans++;
        n /= factor;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int twos = count_factors(n, 2);
        int fives = count_factors(n, 5);

        int zeros = 0;
        llong ans = 0LL;
        bool possible = true;

        while (possible) {
            int needed_twos = max(zeros - twos, 0);
            int needed_fives = max(zeros - fives, 0);

            llong mult = 1LL;
            for (int i = 0; i < needed_twos; i++) mult *= 2LL;
            for (int i = 0; i < needed_fives; i++) mult *= 5LL;

            if (mult > m) possible = false;
            else {
                mult = (m / mult) * mult;
                ans = n * mult;
                zeros++;
            }
        }

        cout << ans << "\n";
    }
}