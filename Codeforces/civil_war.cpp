#include <bits/stdc++.h>

using namespace std;

#define long long long int

int exp(int a, int n) {
    if (!n) return 1;

    int ans = exp(a, n >> 1);
    ans *= ans;

    if (n & 1) ans *= a;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; cin >> N;

    int g = 0;
    for (int i = 0; i < N; i++) {
        int f; cin >> f;
        g = gcd(g, f);
    }

    map<int, int> cnt;
    for (int i = 2; i * i <= g; i++)
        while (!(g % i)) {
            cnt[i]++;
            g /= i;
        }

    if (g > 1) cnt[g]++;

    int ans = 1, p = 2;
    while (true) {
        int curr = 1;
        for (auto [prime, q]: cnt)
            curr *= exp(exp(prime, q / p), p);

        ans = max(ans, curr);
        if (curr < 2) break;
        p++;
    }

    if (ans < 2) cout << "NO CIVIL WAR\n";
    else cout << ans << "\n";
}