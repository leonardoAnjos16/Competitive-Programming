#include <bits/stdc++.h>

using namespace std;

#define llong long long int

const int MAX = 1e5 + 5;
const int MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    bool seen[MAX] = {0}, all_one = true;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        int g = gcd(a, b);
        a /= g; b /= g;

        if (b > 1) all_one = false;

        for (int j = 2; j * j <= b; j++) {
            if (b % j) continue;

            seen[j] = true;
            while (!(b % j))
                b /= j;
        }

        if (b > 1) seen[b] = true;
    }

    if (all_one) cout << "2\n";
    else {
        int ans = 1;
        for (int i = 0; i < MAX; i++)
            if (seen[i])
                ans = (1LL * ans * i) % MOD;

        cout << ans << "\n";
    }
}