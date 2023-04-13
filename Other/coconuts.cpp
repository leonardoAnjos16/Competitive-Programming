#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e5 + 5;

int pow(int a, int n) {
    if (!n) return 1;

    int ans = pow(a, n >> 1);
    ans *= ans;

    if (!(n & 1)) return ans;
    return ans * a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;

    map<int, int> cnt;
    llong sum[MAX] = {0LL};

    for (int i = 0; i < n; i++) {
        int a; cin >> a;

        cnt[a]++;
        int coconuts = a;

        int mx = 0;
        vector<pair<int, int>> factors;

        for (int j = 2; j * j <= a; j++)
            if (!(a % j)) {
                int c = 0;
                while (!(a % j)) {
                    c++;
                    a /= j;
                }

                mx = max(mx, c);
                factors.emplace_back(j, c);
            }

        if (a > 1) {
            mx = max(mx, 1);
            factors.emplace_back(a, 1);
        }

        for (int j = 2; j <= mx; j++) {
            int x = 1;
            bool possible = true;

            for (auto [p, c]: factors) {
                if (c % j) possible = false;
                else x *= pow(p, c / j);
            }

            if (possible) sum[x] += coconuts;
        }
    }

    llong ans = 0LL;
    for (auto [v, c]: cnt)
        ans = max(ans, 1LL * c * v);

    for (int i = 1; i < MAX; i++)
        ans = max(ans, sum[i] + 1LL * i * cnt[i]);

    cout << ans << "\n";
}